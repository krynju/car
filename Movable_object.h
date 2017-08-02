//
// Created by gulin on 27/07/2017.
//

#ifndef CAR_OBJECT_MOVABLE_H
#define CAR_OBJECT_MOVABLE_H

#include <chrono>
#include "Screen.h"

class Movable_object{
public:
    virtual double get_range()=0;
    virtual void update_position(std::chrono::duration<double>)=0;
    virtual void draw(Screen&)=0;
    virtual double getx()=0;
    virtual double gety()=0;
    virtual bool check_if_in_range(double,double,double)=0;
};
#endif //CAR_OBJECT_MOVABLE_H
