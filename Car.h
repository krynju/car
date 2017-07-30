//
// Created by gulin on 27/07/2017.
//

#ifndef CAR_CAR_H
#define CAR_CAR_H

#include <ctime>
#include <chrono>
#include "Movable_object.h"
#include "Screen.h"

class Car : public Movable_object{
private:
    double x;                   //exact position
    double y;
    double x_velocity;          //velocity
    double y_velocity;
    unsigned int x_on_screen;   //rounded to int position
    unsigned int y_on_screen;

public:
    Car(double,double,double,double);
    void update_position(std::chrono::duration<double> time_elapsed) override;
    void draw(Screen &S) override;
    double getx();
    double gety();
};


#endif //CAR_CAR_H
