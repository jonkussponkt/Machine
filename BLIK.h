//
// Created by Admin on 06.12.2020.
//

#ifndef BLIK_H
#define BLIK_H

#include "pay.h"

class BLIK : public pay {
    int code;
public:
    bool payment(Money & price) override;
    int randomize();
    explicit BLIK(int a = 0) : code(a){};
    ~BLIK() override = default;
};


#endif //MIGACZJAN_ETAP1_BLIK_H
