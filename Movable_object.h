//
// Created by gulin on 27/07/2017.
//

#ifndef CAR_OBJECT_MOVABLE_H
#define CAR_OBJECT_MOVABLE_H

#include <chrono>
#include "Screen.h"

class Movable_object {
protected:
    double x, y;                                                //exact position
    double x_velocity, y_velocity;                              //velocity
    int x_on_screen, y_on_screen;                               //rounded to int position
    double minimal_collision_range, critical_collision_range;
public:
    Movable_object(double x, double y, double x_vel, double y_vel, double min_range, double crit_range);

    double get_x();

    double get_y();

    double get_critical_range();

    double get_minimal_range();

    void update_position(std::chrono::duration<double>);

    int check_if_in_range(Movable_object &Obj);

    virtual void draw(Screen &)=0;
};

#endif //CAR_OBJECT_MOVABLE_H
