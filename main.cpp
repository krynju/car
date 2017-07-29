#include <iostream>
#include "Screen.h"
#include "Car.h"
#include <thread>
#include <fstream>
#include <iomanip>


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
//    std::ofstream log;
//    log.open("log.txt");

    Screen a(30, 10);
    Car c(0, 0, 1, 0);
    std::chrono::time_point<std::chrono::system_clock> time_a, time_b;
    time_a = std::chrono::system_clock::now();

    for (int i ;;i++) {
        time_b = std::chrono::system_clock::now();
        c.update_position(time_b-time_a);
        c.draw(a);
        a.display();
        time_a = time_b;

//        double h = c.getx();
//        log << std::setprecision (15) << h << std::endl;
//
//        if(c.getx() > 25)
//            break;

    }
    std::this_thread::sleep_for(std::chrono::seconds(5));


    return 0;
}