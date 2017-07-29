//
// Created by gulin on 27/07/2017.
//

#include <vector>

#ifndef CAR_SCREEN_H
#define CAR_SCREEN_H


class Screen {
private:

    std::vector<std::vector<char>> table;
public:
    Screen(unsigned int, unsigned int);
    void display();
    void fill(char);
    void fill_pixel(unsigned int,unsigned int,char);
    void empty_pixel(unsigned int,unsigned int);
    char view_pixel(int,int);
};


#endif //CAR_SCREEN_H
