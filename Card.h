//
// Created by Admin on 06.12.2020.
//

#ifndef CARD_H
#define CARD_H

#include "pay.h"

class Card : public pay {
public:
    bool payment(Money & to_pay) override;
    Card() = default;
    ~Card() override = default;
};


#endif //MIGACZJAN_ETAP1_CARD_H
