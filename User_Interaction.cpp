//
// Created by Admin on 08.12.2020.
//

#include <iostream>
#include <thread>
#include <chrono>
#include <string>
#include <fstream>
#include "User_Interaction.h"
#include "Exceptions.h"

using namespace std;


void User_Interaction::processing() {
    cout << "Processing";
    for(int i = 0; i < 3; i++) {
        this_thread::sleep_for(chrono::seconds(1));
        cout << ".";
    }
}

int User_Interaction::picking_something() {
    int coin;
    string taken_from_file = get_str();
    coin = atoi(taken_from_file.c_str());
    return coin;
}

int User_Interaction::picking_something(int & code) {
    int choice;
    string taken_from_file = get_str();
    choice = atoi(taken_from_file.c_str());
    if(code != choice)
        throw Wrong_Input();
    return code;
}

int User_Interaction::picking_something(int left_lim, int right_lim) {
    int choice;
    string taken_from_file = get_str();
    choice = atoi(taken_from_file.c_str());
    if(choice < left_lim || choice > right_lim)
        throw Wrong_Input();
    return choice;
}

std::string User_Interaction::get_str(){
    string get;
    if(read_from_file)
        getline(*file_input, get);
    else
        getline(cin, get);
    return get;
}
