#include "Car.h"

Car::Car(double xx, double yy, double xx_vel, double yy_vel) :
        x(xx), x_old(xx),
        y(yy), y_old(yy),
        x_velocity(xx_vel),
        y_velocity(yy_vel) {}

void Car::update_position() {
    double time_elapsed = 1; /*temp variable*/
    x_old = x;
    y_old = y;
    x += x_velocity * time_elapsed;
    y += y_velocity * time_elapsed;

}

void Car::draw(Screen &S) {
    S.empty_pixel((unsigned int) (x_old), (unsigned int) (y_old));
    S.fill_pixel((unsigned int) (x), (unsigned int) (y), 'C');


}




