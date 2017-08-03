#include <cmath>
#include "Movable_object.h"

int Movable_object::check_if_in_range(Movable_object &Obj) {
    auto distance = sqrt(pow(x - Obj.get_x(), 2) + pow(y - Obj.get_y(), 2));
    auto possible_collision_range = minimal_collision_range + Obj.get_minimal_range();
    auto guaranteed_collision_range = critical_collision_range + Obj.get_critical_range();
    enum {no_collision, possible_collision, collision };

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
            critical_collision_range(crit_range){}

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



