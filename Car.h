//
// Created by gulin on 27/07/2017.
//

#ifndef CAR_CAR_H
#define CAR_CAR_H


#include <ctime>
#include "Object_movable.h"
#include "Screen.h"

class Car : public Object_movable{
private:
    double x;
    double y;
    double x_velocity;
    double y_velocity;
    double x_old;
    double y_old;
public:
    Car(double,double,double,double);
    void update_position(std::time_t time_elapsed) override;
    void draw(Screen &S) override;
};


#endif //CAR_CAR_H
