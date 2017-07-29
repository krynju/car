//
// Created by gulin on 27/07/2017.
//

#ifndef CAR_OBJECT_MOVABLE_H
#define CAR_OBJECT_MOVABLE_H

#include <chrono>
#include "Screen.h"

class Object_movable{
public:
    virtual void update_position(std::chrono::duration<double>) = 0;
    virtual void draw(Screen&) = 0;
};
#endif //CAR_OBJECT_MOVABLE_H
