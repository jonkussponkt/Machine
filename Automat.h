//
// Created by Admin on 16.11.2020.
//

#ifndef PROJECT_OBJECT_1_AUTOMAT_H
#define PROJECT_OBJECT_1_AUTOMAT_H

#include "Drink.h"
#include "Money.h"

class Automat{
    int number_of_drinks[4];
    Drink Pepsi;
    Drink Coca_Cola;
    Drink Mirinda;
    Drink Piwniczanka;
    friend void hello(Automat & MACHINE);
public:
    bool is_empty();
    void print_an_offer();
    int choose_a_drink();
    void transaction();
    bool toss_a_coin(Money & to_pay);
    Automat() : number_of_drinks{3,3,3,3}, Pepsi(0, "Pepsi", 2, 0), Coca_Cola(1, "Coca-Cola", 3, 70),
                Mirinda(2, "Mirinda", 6, 10), Piwniczanka(3, "Piwniczanka", 10, 0) {};
    ~Automat(){ cout << "MACHINE IS TURNING OFF"; };
};

#endif //PROJECT_OBJECT_1_AUTOMAT_H
