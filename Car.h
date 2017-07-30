#ifndef CAR_CAR_H
#define CAR_CAR_H

#include <ctime>
#include <chrono>
#include "Movable_object.h"
#include "Screen.h"

class Car : public Movable_object{
private:
    double x;                   //exact position
    double y;
    double x_velocity;          //velocity
    double y_velocity;
    int x_on_screen;   //rounded to int position
    int y_on_screen;
public:
    Car(double,double,double,double);
    void update_position(std::chrono::duration<double> time_elapsed) override;
    void draw(Screen &S) override;
    double getx() override;
    double gety() override;
};


#endif //CAR_CAR_H
