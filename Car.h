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
    unsigned int x_on_screen;
    unsigned int y_on_screen;
    double x;
    double y;
    double x_velocity;
    double y_velocity;

public:
    Car(double,double,double,double);
    void update_position(std::chrono::duration<double> time_elapsed) override;
    void draw(Screen &S) override;
    double getx();
    double gety();
};


#endif //CAR_CAR_H
