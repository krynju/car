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

    double get_x_velocity();

    double get_y_velocity();

    void set_x_velocity(double);

    void set_y_velocity(double);

    double get_x();

    double get_y();

    double set_x(double);

    double set_y(double);

    double get_critical_range();

    double get_minimal_range();

    void update_position(std::chrono::duration<double>);

    int check_range(Movable_object &Obj);

    virtual void draw(Screen &)=0;

    virtual std::vector<std::pair<double, double>> collision_points()=0;

    virtual std::vector<std::pair<double, double>> check_collision(std::vector<std::pair<double, double>>)=0;

    void resolve_collision(Movable_object &);
};

#endif //CAR_OBJECT_MOVABLE_H
