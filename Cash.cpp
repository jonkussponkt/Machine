//
// Created by Admin on 08.12.2020.
//

#include "Cash.h"
#include "Money.h"
#include "User_Interaction.h"
#include "Exceptions.h"

using std::cout;
using std::cin;
using std::endl;

bool Cash::payment(Money & to_pay) {
    /// KLIENT PŁACI GOTÓWKĄ
    try {
        while (!toss_a_coin(to_pay)) ///PRZECHODZIMY DO WRZUCANIA MONETY I SPRAWDZAMY CZY NOMINAL JEST NIE WIĘKSZY NIŻ SUMA DO ZAPŁATY
            cout << "Coin must not be greater than sum to pay\n";
    }
    catch(const Wrong_Input & wrong_input){ /// GDY KTOŚ WPROWADZA ZŁĄ MONETĘ
        std::cout << "AN EXCEPTION WAS THROWN: " << wrong_input.what() << endl;
    }
    catch(const Greater_Value & greater_value){  ///GDY MONETA JEST WIĘKSZA OD CENY
        std::cout << "AN EXCEPTION WAS THROWN: " << greater_value.what() << endl;
    }
    return to_pay != 0;
}

bool Cash::toss_a_coin(Money & to_pay) {
    int coin;
    Money current_sum;
    cout << "Toss a coin! The machine accepts only: 10 gr, 20 gr, 50 gr, 1 zl, 2 zl, 5 zl\nMachine does not give exchange\n";
    cout << "You have to pay " << to_pay << endl;
    coin = User_Interaction::picking_something();///WRZUCAMY MONETĘ
    if (coin != 1 && coin != 2 && coin != 5 && coin != 10 && coin != 20 && coin != 50) {
        throw Wrong_Input();
    }  ///ZABEZPIECZENIE PRZED WPISANIEM NIEPRAWIDŁOWEGO NOMINAŁU
    if(coin == 1 || coin == 2 || coin == 5)
        current_sum.zlote = coin;  ///POWYŻSZE WARTOŚCI SĄ WARTOŚCIAMI ZŁOTYCH
    else
        current_sum.grosze = coin; ///RESZTA WARTOŚCI ODNOSI SIĘ DO WARTOŚCI GROSZY
    if(current_sum <= to_pay){  ///SPRAWDZAMY CZY WRZUCANY NOMINAŁ JEST NIE WIĘKSZY NIŻ KWOTA DO ZAPŁATY, INACZEJ RZUCAMY WYJĄTEK
        to_pay -= current_sum; ///ODEJMUJEMY KWOTĘ WRZUCONĄ OD KWOTY DO ZAPŁATY
        return true;
    }
    else
        throw Greater_Value();
}