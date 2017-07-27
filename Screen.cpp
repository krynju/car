#include "Screen.h"
#include <algorithm>
#include <iostream>

void Screen::display() {
    for_each(table.begin(), table.end(), [](std::vector<char> &table_element) {
        for_each(table_element.begin(), table_element.end(), [](char &pix) {
            std::cout << pix;
        });
        std::cout << std::endl;
    });
}

Screen::Screen(unsigned int xx, unsigned int yy) :
//xx - horizontal resolution, yy - vertical
//vector vectorów rozmiar yy, wypełnienie wektorami o rozmiarze xx
        table(std::vector<std::vector<char>>(yy, std::vector<char>(xx))) {}

void Screen::fill(const char c) {
    for_each(table.begin(), table.end(), [&](std::vector<char> &table_element) {
        for_each(table_element.begin(), table_element.end(), [&](char &pix) {pix = c;});
    });
}

void Screen::fill_pixel(unsigned int x, unsigned int y,char c) {
    table[y][x] = c;
}

void Screen::empty_pixel(unsigned int x, unsigned int y) {
    table[y][x] = ' ';
}
