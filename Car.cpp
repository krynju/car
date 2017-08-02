#include <cmath>
#include <chrono>
#include "Car.h"

Car::Car(double xx, double yy, double xx_vel, double yy_vel) :
/*constructor: initialising all variables*/
        x(xx), x_on_screen((int) std::round(xx)),
        y(yy), y_on_screen((int) std::round(yy)),
        x_velocity(xx_vel),
        y_velocity(yy_vel) {}

void Car::update_position(std::chrono::duration<double> time_elapsed) {
    x += x_velocity * time_elapsed.count();     //calculate objects movement in the time_elapsed
    y += y_velocity * time_elapsed.count();
}

void Car::draw(Screen &S) {
    auto x_t = (int) std::round(x);        //round the exact position variables
    auto y_t = (int) std::round(y);

    if (x_t == x_on_screen && y_t == y_on_screen) { //check if the position changed from the previous state
        if (S.view_pixel(x_t, y_t) != 'C') {        //check if the not changed position is drawn
            S.fill_pixel(x_t, y_t, 'C');            //if not then fill it and set the edited flag to true
            S.screen_edited_flag = true;
        }
        return;
    }
//  else == position changed
    S.empty_pixel(x_on_screen, y_on_screen);        //empty the previous position
    S.fill_pixel(x_t, y_t, 'C');                    //fill the new position
    x_on_screen = x_t;                              //assign new positions to the position variables
    y_on_screen = y_t;
    S.screen_edited_flag = true;                    //set the edited flag to true

}

double Car::getx() {
    return x;
}

double Car::gety() {
    return y;
}

bool Car::check_if_in_range(double xx, double yy ,double range2) {
    return range + range2 > sqrt(pow(x-xx,2) + pow(y-yy,2));
}

double Car::get_range() {
    return range;
}




