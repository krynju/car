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
    /*and resolves collisions with canvas*/
    bool flag = false;
    std::for_each(container.begin(), container.end(), [&](Movable_object *Obj) {
        if (Obj->get_x() > x_size - 1 || Obj->get_x() < 0) {
            Obj->set_x_velocity(-Obj->get_x_velocity());
            flag = true;
        }
        if (Obj->get_y() > y_size - 1 || Obj->get_y() < 0) {
            Obj->set_y_velocity(-Obj->get_y_velocity());
            flag = true;
        }
    });
    return flag;
}

bool Movable_object_container::collision_radar() {
    /*first loop after every element*/
    /*second starting from actual+1 iterator of the main loop*/
    bool flag = false;
    enum {
        no_collision, possible_collision, collision
    };

    for (auto main_loop = container.begin(); main_loop != container.end(); main_loop++) {
        for (auto secondary_loop = main_loop + 1; secondary_loop != container.end(); secondary_loop++) {
            switch ((*main_loop)->check_range(**secondary_loop)) {

                case no_collision:
                    break;
                case possible_collision:
                    if (!(*main_loop)->check_collision((*secondary_loop)->collision_points()).empty()) {
                        (*main_loop)->resolve_collision((**secondary_loop));
                        flag = true;
                    }
                    break;

                case collision:
                    (*main_loop)->resolve_collision((**secondary_loop));
                    flag = true;
                    break;
            }
        }
    }
    return flag;
}




