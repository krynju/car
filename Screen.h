//
// Created by gulin on 27/07/2017.
//

#include <vector>
#include <chrono>

#ifndef CAR_SCREEN_H
#define CAR_SCREEN_H


class Screen {
private:
    std::vector<std::vector<char>> table;
    std::chrono::time_point<std::chrono::system_clock> last_time_displayed;
public:

    Screen(unsigned int, unsigned int);
    void display(std::chrono::time_point<std::chrono::system_clock> time_now);
    void display();
    void fill(char);

    void fill_pixel(unsigned int,unsigned int,char);
    void empty_pixel(unsigned int,unsigned int);
    char view_pixel(int,int);


    bool screen_edited_flag;
};


#endif //CAR_SCREEN_H
