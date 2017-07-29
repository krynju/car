#include <cmath>
#include "Car.h"

Car::Car(double xx, double yy, double xx_vel, double yy_vel) :
        x(xx), x_on_screen((unsigned int) std::round(xx)),
        y(yy), y_on_screen((unsigned int) std::round(yy)),
        x_velocity(xx_vel),
        y_velocity(yy_vel) {}

void Car::update_position(std::time_t time_elapsed) {
    x += x_velocity * time_elapsed;
    y += y_velocity * time_elapsed;
}

void Car::draw(Screen &S) {
    auto x_t = (unsigned int) std::round(x);
    auto y_t = (unsigned int) std::round(y);
    if ( x_t == x_on_screen && y_t == y_on_screen){
        if( S.view_pixel(x_t,y_t) != 'C'){
            S.fill_pixel(x_t,y_t,'C');

        }
        return;
    }
    S.empty_pixel(x_on_screen, y_on_screen);
    S.fill_pixel(x_t, y_t, 'C');
    x_on_screen = x_t;
    y_on_screen = y_t;

}




