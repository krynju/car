#include "Screen.h"
#include <algorithm>
#include <iostream>
#include <chrono>

#define time_point_variable std::chrono::time_point<std::chrono::system_clock>

bool Screen::display(time_point_variable time_now) {
    auto time_a = (time_now - last_time_displayed);
    if (time_a < std::chrono::milliseconds(1000 / 10))
        return false;
//    if (!screen_edited_flag)
//        return false;
    system("cls");
    for_each(table.begin(), table.end(), [](std::vector<char> &table_element) {
        for_each(table_element.begin(), table_element.end(), [](char &pix) {
            std::cout << pix;
        });
        std::cout << std::endl;
    });
    screen_edited_flag = false;
    last_time_displayed = time_now;
    return true;
}

void Screen::display() {
    if (!screen_edited_flag)
        return;
    system("cls");
    for_each(table.begin(), table.end(), [](std::vector<char> &table_element) {
        for_each(table_element.begin(), table_element.end(), [](char &pix) {
            std::cout << pix;
        });
        std::cout << std::endl;
    });
    screen_edited_flag = false;
    last_time_displayed = std::chrono::system_clock::now();
}


Screen::Screen(int xx, int yy) :
//xx - horizontal resolution, yy - vertical
//vector vectorów rozmiar yy, wypełnienie wektorami o rozmiarze xx
        table(std::vector<std::vector<char>>(yy, std::vector<char>(xx))),
        last_time_displayed(std::chrono::system_clock::now()),
        x_size(xx), y_size(yy) {
    screen_edited_flag = true;
}

void Screen::fill(const char c) {
    for_each(table.begin(), table.end(), [&](std::vector<char> &table_element) {
        for_each(table_element.begin(), table_element.end(), [&](char &pix) { pix = c; });
    });
}

void Screen::fill_pixel(int x, int y, char c) {
    if (y > table.size() - 1 || y < 0 || x > table[0].size() - 1 || x < 0)
        throw ("out_of_range");
    table[y_size - 1 - y][x] = c;

}

void Screen::empty_pixel(int x, int y) {
    table[y_size - 1 - y][x] = ' ';
}

char Screen::view_pixel(int x, int y) {
    return table[y_size - 1 - y][x];
}
