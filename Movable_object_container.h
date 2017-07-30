//
// Created by gulin on 29/07/2017.
//

#ifndef CAR_MOVABLE_OBJECT_CONTAINER_H
#define CAR_MOVABLE_OBJECT_CONTAINER_H


#include "Movable_object.h"

class Movable_object_container {
private:
    std::vector<Movable_object*> container;
public:
    void push_back(Movable_object*);
    void update_position(std::chrono::duration<double>);
    void draw(Screen&);
    Movable_object& operator[](int i);
    std::vector<Movable_object*>::iterator begin();
    std::vector<Movable_object*>::iterator end();
};


#endif //CAR_MOVABLE_OBJECT_CONTAINER_H
