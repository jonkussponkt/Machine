//
// Created by Admin on 06.12.2020.
//

#ifndef PAY_H
#define PAY_H

#include "Money.h"

class pay {
public:
    virtual bool payment(Money & to_pay) = 0; ///FUNKCJA CZYSTO WIRTUALNA, KTÓRA STWIERDZA NAM SAM FAKT DOKONYWANIA PŁATNOŚCI
                                             ///FUNKCJE Z KLAS POCHODNYCH BĘDĄ NAM DEFINIOWAĆ KONKRETNE SPOSOBY PŁATNOŚCI
    virtual ~pay() = default;
};


#endif //MIGACZJAN_ETAP1_PAY_H
