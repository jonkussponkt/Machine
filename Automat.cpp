//
// Created by Admin on 16.11.2020.
//

#include "Automat.h"
#include <iostream>
#include <iomanip>

using namespace std;

bool Automat::is_empty() {
    return number_of_drinks[0]==0 && number_of_drinks[1]==0 && number_of_drinks[2] == 0 && number_of_drinks[3] == 0;
}

void Automat::print_an_offer() {
    cout << "THESE ARE DRINKS THAT YOU CAN BUY HERE \n";
    cout << Pepsi << setfill(' ') << setw(11) << number_of_drinks[0] << " items still available " << '\t' << endl;
    cout << Coca_Cola << setfill(' ') << setw(6) << number_of_drinks[1] << " items still available " << endl;
    cout << Mirinda << setfill(' ') << setw(8) << number_of_drinks[2] << " items still available " << endl;
    cout << Piwniczanka << setfill(' ') << setw(4) << number_of_drinks[3] << " items still available " << endl;
}

int Automat::choose_a_drink() {
    int choice;

    /// WYBÓR NAPOJU PRZEZ KUPUJĄCEGO WRAZ Z ZABEZPIECZENIAMI PRZED POMYŁKAMI WE WPROWADZANIU DANYCH
    do {
        cout << "Type the number (1-4) to choose your drink\n";
        cin >> choice;
        if(choice < 1 || choice > 4)
            cout << "Invalid number! Type it once again\n";
        if(number_of_drinks[choice - 1] == 0)
            cout << "Lack of this drink. Pick another one please\n";
    }
    while(choice < 1 || choice > 4 || number_of_drinks[choice - 1] == 0);

    /// PRZECHODZIMY DO TRANSAKCJI
    /// ROZPOCZYNAMY PROCES PŁATNOŚCI POPRZEZ ZWRÓCENIE KWOTY DO ZAPŁATY
    switch(choice){
        case 1:
            return 0;
        case 2:
            return 1;
        case 3:
            return 2;
        case 4:
            return 3;
    }
}

void Automat::transaction(){
    int index = choose_a_drink();
    Money to_pay;
    Money ideal(0,0);
    switch (index) {
        case 0:
            to_pay = Pepsi.price;
            break;
        case 1:
            to_pay = Coca_Cola.price;
            break;
        case 2:
            to_pay = Mirinda.price;
            break;
        case 3:
            to_pay = Piwniczanka.price;
            break;
    }
    while(to_pay != ideal) {
        while (!toss_a_coin(to_pay))
            cout << "Coin must not be greater than sum to pay\n";
    }
    number_of_drinks[index]--;
    cout << "Thanks for purchase! See you again!\n";
}

bool Automat::toss_a_coin(Money & to_pay) {
    int coin;
    Money x;
    cout << "Toss a coin! The machine accepts only: 10 gr, 20 gr, 50 gr, 1 zl, 2 zl, 5 zl\nMachine does not give exchange\n";
    cout << "You have to pay " << to_pay << endl;
    cin >> coin;
    while (coin != 1 && coin != 2 && coin != 5 && coin != 10 && coin != 20 && coin != 50) {
        cout << "INVALID COIN! TYPE YOUR COIN ONCE MORE! You have to pay \n" << to_pay << "\n";
        cin >> coin;
    }
    if(coin == 1 || coin == 2 || coin == 5)
        x.zlote = coin;
    else
        x.grosze = coin;
    if(x <= to_pay){
        to_pay -= x;
        return true;
    }
    return false;
}
