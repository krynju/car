#include <cmath>
#include <chrono>
#include "Car.h"

Car::Car(double xx, double yy, double xx_vel, double yy_vel) :
/*constructor: initialising all variables*/
        Movable_object(xx,yy,xx_vel,yy_vel,sqrt(2),1){}


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







