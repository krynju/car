#include <iostream>
#include "Screen.h"
#include "Car.h"
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

    Screen a(30, 10);
    Car c(0, 0, 1, 1);
    std::chrono::time_point<std::chrono::system_clock> time_a, time_b;
    time_a = std::chrono::system_clock::now();

    for (int i = 0; i < 100; i++) {
        time_b = std::chrono::system_clock::now();
        c.update_position(std::chrono::system_clock::to_time_t(time_b) - std::chrono::system_clock::to_time_t(time_a));
        c.draw(a);
        a.display();
        time_a = time_b;
    }
    std::this_thread::sleep_for(std::chrono::seconds(5));


    return 0;
}