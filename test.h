//
// Created by gulin on 29/07/2017.
//

#ifndef CAR_TEST_H
#define CAR_TEST_H

#include <chrono>
#include <thread>
#include <iostream>
#include "Screen.h"
#include "Car.h"

void test1_standard_w_prawo(){
    Screen a(30, 10);
    Car c(0, 0, 5, 0);

    std::chrono::time_point<std::chrono::system_clock> time_a, time_b;
    std::chrono::time_point<std::chrono::system_clock> fps_count_start,fps_count_end;

    time_a = std::chrono::system_clock::now();
    fps_count_start = std::chrono::system_clock::now();
    int updates = 0;
    for ( ;;++updates) {
        time_b = std::chrono::system_clock::now();
        c.update_position(time_b-time_a);
        c.draw(a);
        a.display();
        time_a = time_b;

        if(c.getx() > 25)
            break;

    }
    fps_count_end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = fps_count_end-fps_count_start;
    std::cout << "time elapsed: " << elapsed_seconds.count() <<std::endl;
    std::cout << "updates per second: " << updates/elapsed_seconds.count();


    std::this_thread::sleep_for(std::chrono::seconds(5));

}

#endif //CAR_TEST_H
