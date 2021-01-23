//
// Created by Admin on 16.11.2020.
//

#ifndef DRINK_H
#define DRINK_H

#include <string>
#include <utility>

#include "Money.h"

using namespace std;

class Drink{
    int ID;
    string name;
    Money price;
    friend class Automat;
public:
    friend ostream & operator<<(ostream & stream, Drink & drink);
    Drink(int number = 0, string title = "", int zl = 0, int gr = 0) : ID(number), name(move(title)), price(zl, gr){};
    ~Drink() = default;
};

#endif //PROJECT_OBJECT_1_DRINK_H
