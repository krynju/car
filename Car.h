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

    std::vector<std::pair<double, double>> collision_points() override;
    std::vector<std::pair<double, double>> check_collision(std::vector<std::pair<double, double>> Vec) override;

};


#endif //CAR_CAR_H
