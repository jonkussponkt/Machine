//
// Created by Admin on 08.12.2020.
//

#ifndef USER_INTERACTION_H
#define USER_INTERACTION_H

#include <string>
#include <iostream>


class User_Interaction {
public:
    static std::ifstream * file_input;
    static bool read_from_file;
    static void processing();
    static int picking_something();
    static int picking_something(int & code);
    static int picking_something(int left_lim, int right_lim);
    static std::string get_str();
};


#endif //MIGACZJAN_ETAP1_USER_INTERACTION_H
