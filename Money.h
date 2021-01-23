//
// Created by Admin on 16.11.2020.
//

#ifndef MONEY_H
#define MONEY_H

#include <iostream>

using std::ostream;

class Money {
    int zlote;
    int grosze;
    friend class Cash;
public:
    Money operator-=(Money & money);
    Money & operator=(const Money & money);
    bool operator!=(int to_compare) const;
    bool operator<=(Money & money) const;
    friend ostream & operator<<(ostream & os, Money & money);
    explicit Money(int nr_of_zl = 0, int nr_of_gr = 0) : zlote(nr_of_zl), grosze(nr_of_gr){};
};


#endif //PROJECT_OBJECT_1_MONEY_H
