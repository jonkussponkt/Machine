//
// Created by Admin on 18.12.2020.
//

#include "Automat.h"
#include "User_Interaction.h"
#include <fstream>

bool User_Interaction::read_from_file = false;
std::ifstream * User_Interaction::file_input = nullptr;

int main(int argc, char * argv[]){

    if(argc == 2) {
        ifstream read;
        read.open(argv[1]);
        if(!read.good())
            std::cout << "An unexpected error occurred\n";
        User_Interaction::file_input = &read;
        User_Interaction::read_from_file = true;
        Automat MACHINE;
        MACHINE.hello();
        read.close();
    }
    else{
        Automat MACHINE;
        MACHINE.hello();
    }
    return 0;
}