//
// Created by Admin on 16.11.2020.
//

#ifndef PROJECT_OBJECT_1_DRINK_H
#define PROJECT_OBJECT_1_DRINK_H

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
    Drink(int a = 0, string b = " ", int zl = 0, int gr = 0) : ID(a), name(move(b)), price(zl, gr){};
    Drink & operator=(const Drink & drink);
    ~Drink() = default;
};

#endif //PROJECT_OBJECT_1_DRINK_H
