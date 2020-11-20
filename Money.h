//
// Created by Admin on 16.11.2020.
//

#ifndef PROJECT_OBJECT_1_MONEY_H
#define PROJECT_OBJECT_1_MONEY_H

#include <iostream>

using std::ostream;

class Money {
    int zlote;
    int grosze;
    friend class Automat;
public:
    Money operator-=(Money & money);
    Money & operator=(const Money & money);
    bool operator!=(Money & money) const;
    bool operator<=(Money & money) const;
    friend ostream & operator<<(ostream & os, Money & money);
    Money(int a = 0, int b = 0) : zlote(a), grosze(b){};
};


#endif //PROJECT_OBJECT_1_MONEY_H
