//
// Created by Admin on 16.11.2020.
//

#include "Money.h"
#include "Exceptions.h"

using namespace std;

Money Money::operator-=(Money &money) {  ///PRZECIĄŻONY OPERATOR -= DLA LEKKIEGO PRZEPROWADZENIA OPERACJI
    zlote -= money.zlote;               ///ODJĘCIA KWOTY DO ZAPŁĄTY
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

bool Money::operator!=(int to_compare) const {
    return zlote != to_compare || grosze != to_compare;
}

bool Money::operator<=(Money & money) const{
    if(zlote == money.zlote)
        return grosze <= money.grosze;
    else
        return zlote <= money.zlote;
}

ostream & operator<<(ostream & os, Money & money){
    os << money.zlote << " zl";
    if(money.grosze > 0)
        os << ", " << money.grosze << " gr";
    return os;
}
