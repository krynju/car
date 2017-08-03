#ifndef CAR_CAR_H
#define CAR_CAR_H

#include <ctime>
#include <chrono>
#include "Movable_object.h"
#include "Screen.h"

class Car : public Movable_object {
public:
    Car(double, double, double, double);

    void draw(Screen &S) override;


};


#endif //CAR_CAR_H
