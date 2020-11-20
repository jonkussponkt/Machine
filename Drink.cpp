//
// Created by Admin on 16.11.2020.
//

#include "Drink.h"
#include <iostream>

using namespace std;

ostream & operator<<(ostream & stream, Drink & drink) {
    return stream << drink.ID+1 << ". " << drink.name << " " << drink.price;
}

Drink & Drink::operator=(const Drink &drink) {
    if(&drink == this)
        return *this;
    this->price = drink.price;
    this->name = drink.name;
    this->ID = drink.ID;
    return *this;
}
