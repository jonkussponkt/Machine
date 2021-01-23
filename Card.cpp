//
// Created by Admin on 06.12.2020.
//

#include "Card.h"
#include "User_Interaction.h"

using std::cout;

bool Card::payment(Money & to_pay) {
    cout << "Press any character on your keyboard to bring your card closer\n";
    ///PŁATNOŚĆ ZBLIZENIOWA (WSZYSTKIE NAPOJE SĄ TAŃSZE NIŻ 50 ZŁ WIĘC NIE TRZEBA WPROWADZAĆ PINU)
    ///MOŻNA WPROWADZIĆ CHOĆBY ENTER
    User_Interaction::get_str();
    return false;
}

