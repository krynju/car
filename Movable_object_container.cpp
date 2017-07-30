#include <algorithm>
#include "Movable_object_container.h"

void Movable_object_container::push_back(Movable_object &Obj) {
    container.push_back(&Obj);
}

void Movable_object_container::update_position(std::chrono::duration<double> time) {
    /*lambda expression, update every objects position in the container*/
    std::for_each(container.begin(), container.end(),
                  [&time](Movable_object *Obj) { (*Obj).update_position(time); });
}

void Movable_object_container::draw(Screen &S) {
    /*lambda expression, draw every object in the container*/
    std::for_each(container.begin(), container.end(),
                  [&S](Movable_object *Obj) { (*Obj).draw(S); });
}

Movable_object &Movable_object_container::operator[](int i) {
    return *(container[i]);
}

std::vector<Movable_object *>::iterator Movable_object_container::begin() {
    return container.begin();
}

std::vector<Movable_object *>::iterator Movable_object_container::end() {
    return container.end();
}

bool Movable_object_container::check_boundaries(int x_size, int y_size) {
    /*lambda expression, checks if every object in the container is withing boundaries*/

    return container.end() == std::find_if(container.begin(), container.end(),
                                           [&](Movable_object *Obj) {
                                               return (*Obj).getx() > x_size - 1 || (*Obj).getx() < 0 ||
                                                      (*Obj).gety() > y_size - 1 || (*Obj).gety() < 0;
                                           });
}




