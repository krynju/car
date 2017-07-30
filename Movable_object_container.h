#ifndef CAR_MOVABLE_OBJECT_CONTAINER_H
#define CAR_MOVABLE_OBJECT_CONTAINER_H


#include "Movable_object.h"

class Movable_object_container {
private:
    std::vector<Movable_object *> container;
public:
    void push_back(Movable_object &);                        //add object to the container
    void update_position(std::chrono::duration<double>);    //update objects positions
    void draw(Screen &);                                     //draw objects to the screen
    bool check_boundaries(unsigned int,unsigned int);
    Movable_object &operator[](int i);

    std::vector<Movable_object *>::iterator begin();

    std::vector<Movable_object *>::iterator end();
};

#endif //CAR_MOVABLE_OBJECT_CONTAINER_H