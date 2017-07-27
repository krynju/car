#include <iostream>
#include "Screen.h"
#include "Car.h"
#include <cstdio>
#include <thread>


int main() {
//    Screen a(15,5);
//    a.display();
//    std::this_thread::sleep_for(std::chrono::seconds(1));
//    system("cls");
//    a.fill('G');
//    a.display();
//    std::this_thread::sleep_for(std::chrono::seconds(1));
//    system("cls");
//    a.fill('%');
//    a.display();
//    std::this_thread::sleep_for(std::chrono::seconds(1));

    Screen a(10,10);
    Car c(3,3,1,1);
    a.fill('t');
    c.update_position();
    c.draw(a);

    a.display();

    return 0;
}