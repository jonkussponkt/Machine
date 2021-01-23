//
// Created by Admin on 08.12.2020.
//

#ifndef CASH_H
#define CASH_H

#include "pay.h"
#include "Money.h"

class Cash : public pay{
public:
    bool payment(Money & to_pay) override;
    bool toss_a_coin(Money & to_pay);
    Cash() = default;
    ~Cash() override = default;
};


#endif //MIGACZJAN_ETAP1_CASH_H
