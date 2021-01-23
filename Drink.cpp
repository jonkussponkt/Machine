//
// Created by Admin on 16.11.2020.
//

#include "Drink.h"
#include <iostream>

using namespace std;

ostream & operator<<(ostream & stream, Drink & drink) {
    return stream << drink.ID+1 << ". " << drink.name << " " << drink.price;
}
