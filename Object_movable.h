//
// Created by gulin on 27/07/2017.
//

#ifndef CAR_OBJECT_MOVABLE_H
#define CAR_OBJECT_MOVABLE_H

#include "Screen.h"

class Object_movable{
public:
    virtual void update_position(std::time_t) = 0;
    virtual void draw(Screen&) = 0;
};
#endif //CAR_OBJECT_MOVABLE_H
