//
// Created by Admin on 16.11.2020.
//

#include "Automat.h"
#include "pay.h"
#include "BLIK.h"
#include "Card.h"
#include "Cash.h"
#include "User_Interaction.h"
#include <iostream>
#include <iomanip>

using namespace std;

string Automat::add_to_print(int i) {
    return number_of_drinks[i]==1 ? " item still available\n" : " items still available \n";
}

void Automat::print_an_offer() {
    cout << "THESE ARE DRINKS THAT YOU CAN BUY HERE \n";
    cout << drinks[0] << setfill(' ') << setw(17) << number_of_drinks[0] << add_to_print(0);
    cout << drinks[1] << setfill(' ') << setw(6) << number_of_drinks[1] << add_to_print(1);
    cout << drinks[2] << setfill(' ') << setw(8) << number_of_drinks[2] << add_to_print(2);
    cout << drinks[3] << setfill(' ') << setw(10) << number_of_drinks[3] << add_to_print(3);
}

void Automat::hello() {
    int choice = -1;
    int index = -1;
    int leave;

    while (true) {
        cout << "WELCOME IN OUR MACHINE!\n";  /// ROZPOCZYNAMY ZAKUPY
        if (number_of_drinks.is_empty()) {  /// SPRAWDZAMY CZY MASZYNA JEST PUSTA I NIE MA W NIEJ NAPOJÓW
            cout << "The machine is empty! Wait for next delivery :(\n";
            break;  /// W TAKIM WYPADKU WYCHODZIMY Z PĘTLI I KOŃCZYMY ZAKUP
        }
        else {
            do {
                do {
                    try{
                        cout << "Press 1 to start a purchase\nPress 2 to leave\n";
                        choice = User_Interaction::picking_something(1, 2);
                    }
                    catch (const Wrong_Input &wrong_input) {
                        cout << "AN EXCEPTION WAS THROWN : " << wrong_input.what() << endl;
                    }
                }
                while(choice < 1 || choice > 2);

                if (choice == 2) {
                    cout << "Are you sure that you want to leave?\n";
                    cout << "If so, press 1, otherwise press anything on your keyboard\n";
                    try {
                        leave = User_Interaction::picking_something();
                        if (leave == 1)
                            break;
                    }
                    catch (const Wrong_Input &wrong_input) {
                        cout << "AN EXCEPTION WAS THROWN: " << wrong_input.what() << endl;
                    }
                }
            }
            while (choice != 1 && choice != 2);

            if (choice == 2 && leave == 1)
                break;
            do {
                print_an_offer(); ///NA POCZĄTEK POKAZUJEMY KLIENTOWI OFERTĘ NAPOJÓW
                do {
                    try {
                        index = choose_a_drink();
                    }
                    catch(Wrong_Input & wrong_input){
                        index = -1;
                        cout << "AN EXCEPTION WAS THROWN: " << wrong_input.what() << endl;
                    }
                    catch(Zero_Drink & zero_drink){
                        index = -1;
                        cout << "AN EXCEPTION WAS THROWN: " << zero_drink.what() << endl;
                    }
                }
                while (index == -1 || number_of_drinks[index] == 0);

                do {
                    try {
                        cout << "Press 1 to continue the purchase\n"
                                "Press 2 to change your choice\n"
                                "Press 3 to finish the transaction\n";
                        choice = User_Interaction::picking_something(1, 3);
                    }
                    catch (const Wrong_Input &wrong_input) {
                        choice = -1;
                        cout << "AN EXCEPTION WAS THROWN: " << wrong_input.what() << endl;
                    }
                }
                while(choice == -1);
            }
            while(choice == 2);

            if (choice == 1)
                transaction(index); ///PRZECHODZIMY DO TRANSAKCJI
            else {
                cout << "Are you sure that you want to leave?\n";
                cout << "If so, press 1, otherwise press anything on your keyboard\n";
                leave = User_Interaction::picking_something();
                if (leave == 1)
                    break;
            }
            choice = -1;
        }
    }
    cout << "Let's throw an exception Improper_Range right now:\n";
    try {
        cout << number_of_drinks[4];
    }
    catch(Improper_Range & improper_range){
        cout << "AN EXCEPTION WAS THROWN: " << improper_range.what() << endl;
    }
}

int Automat::choose_a_drink() {
    int choice;
    /// WYBÓR NAPOJU PRZEZ KUPUJĄCEGO WRAZ Z ZABEZPIECZENIAMI PRZED POMYŁKAMI WE WPROWADZANIU DANYCH
    cout << "Type the number (1-4) to choose your drink\n";
    choice = User_Interaction::picking_something(1, 4);
    if(choice < 1 || choice > 4)
        throw Wrong_Input();
    else if(number_of_drinks[choice - 1] == 0)
        throw Zero_Drink(); ///RZUCAMY WYJĄTEK, GDY KTOŚ POPROSI O NAPÓJ KTÓREGO JUŻ W AUTOMACIE NIE MA
    /// PRZECHODZIMY DO TRANSAKCJI
    /// ROZPOCZYNAMY PROCES PŁATNOŚCI POPRZEZ ZWRÓCENIE KWOTY DO ZAPŁATY
    return drinks[choice - 1].ID;
}

void Automat::transaction(int & index){
    int choice = -1;
    Money to_pay = drinks[index].price;
    cout << "You have to pay " << to_pay << endl;
    cout << "Choose the way of payment \nPress 1 - to pay cash\nPress 2 - to pay by BLIK\nPress 3 - to pay by credit card\n";
    do {
        try {
            choice = User_Interaction::picking_something(1, 3);
        }
        catch (const Wrong_Input &wrong_input) {
            cout << "AN EXCEPTION WAS THROWN: " << wrong_input.what() << endl;
        }
    }
    while(choice != 1 && choice != 2 && choice != 3);


    pay * pointer_to_way; /// WSKAŹNIK DO KLASY PODSTAWOWEJ, KTÓRYM BĘDZIEMY SIĘ POSŁUGIWAĆ PRZY METODACH PŁATNOŚCI
                        ///  I PRZY POLIMORFIZMIE)

    if (choice == 1)
        pointer_to_way = new Cash;
    else if (choice == 2)
        pointer_to_way = new BLIK;
    else
        pointer_to_way = new Card;
    while (true) {
        if (!pointer_to_way->payment(to_pay)) {
            number_of_drinks[index]--;  ///PO KUPNIE NAPOJU JEGO ILOŚĆ ZMNIEJSZAMY O JEDEN
            User_Interaction::processing();
            cout << "\nThanks for purchase! See you again!\n";
            break;
        }
        else {
            if(choice == 2)
                break;
        }
    }
    delete pointer_to_way;
}
