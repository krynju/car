//
// Created by gulin on 29/07/2017.
//

#include <algorithm>
#include "Movable_object_container.h"

void Movable_object_container::push_back(Movable_object *Obj) {
    container.push_back(Obj);
}

void Movable_object_container::update_position(std::chrono::duration<double> time) {
    std::for_each(container.begin(),container.end(),
                  [&time](Movable_object *Obj){(*Obj).update_position(time);});
}

void Movable_object_container::draw(Screen &S) {
    std::for_each(container.begin(),container.end(),
                  [&S](Movable_object *Obj){(*Obj).draw(S);});
}

Movable_object& Movable_object_container::operator[](int i) {
    return *(container[i]);
}

std::vector<Movable_object *>::iterator Movable_object_container::begin() {
    return container.begin();
}

std::vector<Movable_object *>::iterator Movable_object_container::end() {
    return container.end();
}




