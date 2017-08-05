#ifndef CAR_TEST_H
#define CAR_TEST_H

#include <chrono>
#include <thread>
#include <iostream>
#include <algorithm>
#include "Screen.h"
#include "Car.h"
#include "Movable_object_container.h"

#define time_point_variable std::chrono::time_point<std::chrono::system_clock>
#define wait_seconds(x) std::this_thread::sleep_for(std::chrono::seconds(5));

void standard_loop_test() {
    unsigned int x_size = 30;   //screen size
    unsigned int y_size = 10;

    Movable_object_container cont;  //initialise object container
    Car c1(0, 0, 9, 3);             //initialise objects
    Car c2(29, 9, -9, -3);
    Car c3(29,2,-2,0);
    Car c4(29,3,-4,0);
    Car c5(0, 4, 5, 0);
    Car c6(29, 4, -5, 0);

    cont.push_back(c1);            //add objects to the container
    cont.push_back(c2);
    cont.push_back(c3);
    cont.push_back(c4);
    cont.push_back(c5);
    cont.push_back(c6);

    Screen S(x_size, y_size);        //create a screen object

    time_point_variable time_a, time_b;                 //initialise time variables
    time_point_variable ups_count_start, ups_count_end; //updates per second variables

    int updates = 0;                                    //updates counter
    int frames = 0;
    time_a = std::chrono::system_clock::now();          //save starting timestamp
    ups_count_start = std::chrono::system_clock::now(); //starting timestamp for ups

    for (;; ++updates) {
        time_b = std::chrono::system_clock::now();      //save reference timestamp
        cont.update_position(time_b - time_a);          //update position of objects contained in the container
        cont.check_boundaries(x_size, y_size);

        cont.collision_radar();


        cont.draw(S);                                   //draw the objects to the screen
        if (S.display(std::chrono::system_clock::now())) //display the screen
            ++frames;
        time_a = time_b;                                //swap the timestamp


    }

    /*ups info and time elapsed print*/
    ups_count_end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = ups_count_end - ups_count_start;
    std::cout << "time elapsed: " << elapsed_seconds.count() << std::endl;
    std::cout << "updates per second: " << updates / elapsed_seconds.count() << std::endl;
    std::cout << "average frames per second: " << frames / elapsed_seconds.count() << std::endl;


    wait_seconds(5);
}


void standard_loop() {
    unsigned int x_size = 30;   //screen size
    unsigned int y_size = 10;

    Movable_object_container cont;  //initialise object container
    Car c1(0, 0, 1, 0);             //initialise objects
    Car c2(0, 1, 1, 0);
    cont.push_back(c1);            //add objects to the container
    cont.push_back(c2);

    Screen S(x_size, y_size);        //create a screen object

    time_point_variable time_a, time_b;                 //initialise time variables
    time_point_variable ups_count_start, ups_count_end; //updates per second variables

    int updates = 0;                                    //updates counter
    time_a = std::chrono::system_clock::now();          //save starting timestamp
    ups_count_start = std::chrono::system_clock::now(); //starting timestamp for ups

    for (;; ++updates) {
        time_b = std::chrono::system_clock::now();      //save reference timestamp
        cont.update_position(time_b - time_a);          //update position of objects contained in the container
        cont.draw(S);                                   //draw the objects to the screen
        S.display();                                    //display the screen
        time_a = time_b;                                //swap the timestamp

        if (c1.get_x() > x_size - 1 || c1.get_y() > y_size - 1)//break conditions (screen borders)
            break;
        if (c2.get_x() > x_size - 1 || c2.get_y() > y_size - 1)
            break;
    }

    /*ups info and time elapsed print*/
    ups_count_end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = ups_count_end - ups_count_start;
    std::cout << "time elapsed: " << elapsed_seconds.count() << std::endl;
    std::cout << "updates per second: " << updates / elapsed_seconds.count();
    wait_seconds(5);
}

void test1_standard_w_prawo() {
    Screen a(30, 10);
    Car c(0, 0, 5, 0);

    std::chrono::time_point<std::chrono::system_clock> time_a, time_b;
    std::chrono::time_point<std::chrono::system_clock> ups_count_start, ups_count_end;

    time_a = std::chrono::system_clock::now();
    ups_count_start = std::chrono::system_clock::now();
    int updates = 0;
    for (;; ++updates) {
        time_b = std::chrono::system_clock::now();
        c.update_position(time_b - time_a);
        c.draw(a);
        a.display();
        time_a = time_b;

        if (c.get_x() > 25)
            break;

    }
    ups_count_end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = ups_count_end - ups_count_start;
    std::cout << "time elapsed: " << elapsed_seconds.count() << std::endl;
    std::cout << "updates per second: " << updates / elapsed_seconds.count();


    std::this_thread::sleep_for(std::chrono::seconds(5));

}

void test2_movable_object_container_algorytmy() {
    Movable_object_container cont;
    Car c1(0, 0, 1, 0);
    Car c2(0, 1, 2, 0);
    cont.push_back(c1);
    cont.push_back(c2);

    Screen S(30, 10);

    std::chrono::time_point<std::chrono::system_clock> time_a, time_b;
    std::chrono::time_point<std::chrono::system_clock> ups_count_start, ups_count_end;

    time_a = std::chrono::system_clock::now();
    ups_count_start = std::chrono::system_clock::now();
    int updates = 0;
    for (;; ++updates) {
        time_b = std::chrono::system_clock::now();
        cont.update_position(time_b - time_a);
        cont.draw(S);
        S.display();
        time_a = time_b;

        if (c1.get_x() > 25)
            break;
        if (c2.get_x() > 25)
            break;

    }
    ups_count_end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = ups_count_end - ups_count_start;
    std::cout << "time elapsed: " << elapsed_seconds.count() << std::endl;
    std::cout << "updates per second: " << updates / elapsed_seconds.count();


    std::this_thread::sleep_for(std::chrono::seconds(5));

}

#endif //CAR_TEST_H
