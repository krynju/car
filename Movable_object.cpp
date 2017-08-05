#include <cmath>
#include "Movable_object.h"

int Movable_object::check_range(Movable_object &Obj) {
    auto distance = sqrt(pow(x - Obj.get_x(), 2) + pow(y - Obj.get_y(), 2));
    auto possible_collision_range = minimal_collision_range + Obj.get_minimal_range();
    auto guaranteed_collision_range = critical_collision_range + Obj.get_critical_range();
    enum {
        no_collision, possible_collision, collision
    };

    if (distance > possible_collision_range)
        return no_collision;
    if (distance > guaranteed_collision_range)
        return possible_collision;
    if (distance < guaranteed_collision_range)
        return collision;
}

Movable_object::Movable_object(double xx, double yy, double x_vel, double y_vel, double min_range, double crit_range) :
/*constructor: initialising all variables*/
        x(xx),
        y(yy),
        x_on_screen((int) std::round(xx)),
        y_on_screen((int) std::round(yy)),
        x_velocity(x_vel),
        y_velocity(y_vel),
        minimal_collision_range(min_range),
        critical_collision_range(crit_range) {}

double Movable_object::get_minimal_range() {
    return minimal_collision_range;
}

double Movable_object::get_critical_range() {
    return critical_collision_range;
}

double Movable_object::get_x() {
    return x;
}

double Movable_object::get_y() {
    return y;
}

void Movable_object::update_position(std::chrono::duration<double> time_elapsed) {
    x += x_velocity * time_elapsed.count();     //calculate objects movement in the time_elapsed
    y += y_velocity * time_elapsed.count();
}


void Movable_object::resolve_collision(Movable_object &Obj) {
    double omega = atan2(Obj.get_y() - this->get_y(), Obj.get_x() - this->get_y());
    double teta_1 = atan2(this->get_y_velocity(), this->get_x_velocity());
    double teta_2 = atan2(Obj.get_y_velocity(), Obj.get_x_velocity());

    double v1 = sqrt(pow(this->get_x_velocity(), 2) + pow(this->get_y_velocity(), 2));
    double v2 = sqrt(pow(Obj.get_x_velocity(), 2) + pow(Obj.get_y_velocity(), 2));

    double v1xr = v1 * cos(teta_1 - omega);
    double v1yr = v1 * sin(teta_1 - omega);
    double v2xr = v2 * cos(teta_2 - omega);
    double v2yr = v2 * sin(teta_2 - omega);

    this->set_x_velocity(v2xr * cos(omega) + v1yr * cos(omega + M_PI / 2));
    this->set_y_velocity(v2xr * sin(omega) + v1yr * sin(omega + M_PI / 2));
    Obj.set_x_velocity(v1xr * cos(omega) + v2yr * cos(omega + M_PI / 2));
    Obj.set_y_velocity(v1xr * sin(omega) + v2yr * sin(omega + M_PI / 2));

    /*IN CASE I START SUPPORTING MASS*/
//    double mass1 = 1;
//    double mass2 = 1;
//
//    double omega = atan2(Obj.get_y() - this->get_y(), Obj.get_x() - this->get_y());
//
//    double teta_1= atan2(this->get_y_velocity(),this->get_x_velocity());
//    double teta_2= atan2(Obj.get_y_velocity(),Obj.get_x_velocity());
//
//    double v1 = sqrt(pow(this->get_x_velocity(),2)+pow(this->get_y_velocity(),2));
//    double v2 = sqrt(pow(Obj.get_x_velocity(),2)+pow(Obj.get_y_velocity(),2));
//
//    double v1xr = v1*cos(teta_1-omega);
//    double v1yr = v1*sin(teta_1-omega);
//    double v2xr = v2*cos(teta_2-omega);
//    double v2yr = v2*sin(teta_2-omega);
//
//    double v1fxr = (v1xr*(mass1-mass2) + 2*mass2*v2xr)/(mass1+mass2);
//    double v2fxr = (v2xr*(mass2-mass1) + 2*mass1*v1xr)/(mass1+mass2);
//
//    double v1fx = v1fxr*cos(omega)+v1yr*cos(omega+M_PI/2);
//    double v1fy = v1fxr*sin(omega)+v1yr*sin(omega+M_PI/2);
//    double v2fx = v2fxr*cos(omega)+v2yr*cos(omega+M_PI/2);
//    double v2fy = v2fxr*sin(omega)+v2yr*sin(omega+M_PI/2);
//
//    this->set_x_velocity(v1fx);
//    this->set_y_velocity(v1fy);
//    Obj.set_x_velocity(v2fx);
//    Obj.set_y_velocity(v2fy);
}

double Movable_object::get_x_velocity() {
    return x_velocity;
}

double Movable_object::get_y_velocity() {
    return y_velocity;
}

void Movable_object::set_x_velocity(double d) {
    x_velocity = d;
}

void Movable_object::set_y_velocity(double d) {
    y_velocity = d;
}


double Movable_object::set_x(double d) {
    x = d;
}

double Movable_object::set_y(double d) {
    y = d;
}



