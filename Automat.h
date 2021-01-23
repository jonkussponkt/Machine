//
// Created by Admin on 16.11.2020.
//

#ifndef AUTOMAT_H
#define AUTOMAT_H

#include "Drink.h"
#include "Money.h"
#include "Container.h"

class Automat{
    Container<int, 4> number_of_drinks;
    Drink drinks[4];
public:
    void hello();
    string add_to_print(int i);
    void print_an_offer();
    int choose_a_drink();
    void transaction(int & index);
    explicit Automat() : drinks{Drink(0, "Pepsi", 2, 0),
                                Drink(1, "Coca-Cola", 3, 70),
                                Drink(2, "Mirinda", 6, 10),
                                Drink(3, "Piwniczanka", 10, 0)}{
        for(int i = 0; i < 4; i++)
            number_of_drinks[i] = 3;
    }
    ~Automat(){
        cout << "MACHINE IS TURNING OFF";
    }
};

#endif //PROJECT_OBJECT_1_AUTOMAT_H
