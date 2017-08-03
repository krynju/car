#include <algorithm>
#include "Movable_object_container.h"

void Movable_object_container::push_back(Movable_object &Obj) {
    container.push_back(&Obj);
}

void Movable_object_container::update_position(std::chrono::duration<double> time) {
    /*lambda expression, update every objects position in the container*/
    std::for_each(container.begin(), container.end(),
                  [&time](Movable_object *Obj) { Obj->update_position(time); });
}

void Movable_object_container::draw(Screen &S) {
    /*lambda expression, draw every object in the container*/
    std::for_each(container.begin(), container.end(),
                  [&S](Movable_object *Obj) { Obj->draw(S); });
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
    /*returns true if any object reached the boundaries*/
    return !(container.end() == std::find_if(container.begin(), container.end(),
                                             [&](Movable_object *Obj) {
                                                 return Obj->get_x() > x_size - 1 || Obj->get_x() < 0 ||
                                                        Obj->get_y() > y_size - 1 || Obj->get_y() < 0;
                                             }));
}

bool Movable_object_container::collision_radar() {
    /*first loop after every element*/
    /*second starting from actual+1 iterator of the main loop*/
    enum {
        no_collision, possible_collision, collision
    };

    for (auto main_loop = container.begin(); main_loop != container.end(); main_loop++) {
        for (auto secondary_loop = main_loop + 1; secondary_loop != container.end(); secondary_loop++) {
            switch ((*main_loop)->check_if_in_range(**secondary_loop)) {
                case no_collision:
                    continue;
                case possible_collision:
                    //check if real collision
                    return true;
                case collision:
                    //for now return true
                    //todo a collision resolving system
                    return true;
            }
        }
    }
    return false;
}




