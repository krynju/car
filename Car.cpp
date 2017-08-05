#include <cmath>
#include <chrono>
#include <algorithm>
#include "Car.h"

Car::Car(double xx, double yy, double xx_vel, double yy_vel, char s) :
/*constructor: initialising all variables*/
        Movable_object(xx, yy, xx_vel, yy_vel, sqrt(2) / 2, 0.25),
        sign(s) {}


void Car::draw(Screen &S) {
    auto x_t = (int) x;        //round the exact position variables
    auto y_t = (int) y;

    if (x_t == x_on_screen && y_t == y_on_screen) { //check if the position changed from the previous state
        if (S.view_pixel(x_t, y_t) != sign) {        //check if the not changed position is drawn
            S.fill_pixel(x_t, y_t, sign);            //if not then fill it and set the edited flag to true
            S.screen_edited_flag = true;
        }
        return;
    }
//  else == position changed
    S.empty_pixel(x_on_screen, y_on_screen);        //empty the previous position
    S.fill_pixel(x_t, y_t, sign);                    //fill the new position
    x_on_screen = x_t;                              //assign new positions to the position variables
    y_on_screen = y_t;
    S.screen_edited_flag = true;                    //set the edited flag to true
}


std::vector<std::pair<double, double>> Car::collision_points() {
    std::vector<std::pair<double, double>> vec;
    vec.emplace_back(std::make_pair(x - 0.5, y + 0.5));
    vec.emplace_back(std::make_pair(x - 0.5, y - 0.5));
    vec.emplace_back(std::make_pair(x + 0.5, y + 0.5));
    vec.emplace_back(std::make_pair(x + 0.5, y - 0.5));
    return vec;
}

std::vector<std::pair<double, double>> Car::check_collision(const std::vector<std::pair<double, double>> Vec) {
    std::vector<std::pair<double, double>> Ret;
    for (const auto &i : Vec) {
        if (i.first > x - 0.5 &&
            i.first < x + 0.5 &&
            i.second > y - 0.5 &&
            i.second < y + 0.5)
            Ret.emplace_back(i);
    }
    return Ret;

}







