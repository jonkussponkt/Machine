//
// Created by Admin on 16.11.2020.
//

#include "Money.h"

using namespace std;

Money Money::operator-=(Money &money) {
    zlote -= money.zlote;
    grosze -= money.grosze;
    if(grosze < 0){
        zlote--;
        grosze = 100 - abs(grosze);
    }
    return *this;
}

Money & Money::operator=(const Money & money) {
    if(&money == this)
        return *this;
    this->zlote = money.zlote;
    this->grosze = money.grosze;
    return *this;
}

bool Money::operator!=(Money & money) const {
    return zlote != money.zlote || grosze != money.grosze;
}

bool Money::operator<=(Money & money) const{
    return zlote <= money.zlote || (zlote == money.zlote && grosze <= money.grosze);
}

ostream & operator<<(ostream & os, Money & money){
    return os << money.zlote << " zl, " << money.grosze << " gr";
}
