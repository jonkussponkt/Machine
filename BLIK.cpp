//
// Created by Admin on 06.12.2020.
//

#include "BLIK.h"
#include "User_Interaction.h"
#include "Exceptions.h"

#include <iostream>
#include <chrono>
#include <random>

using namespace std;

bool BLIK::payment(Money & price) {
    int input;
    cout << "Type here unique code of 6 digits\nYou've got thirty seconds to pay\n";
    randomize();
    cout << code << endl;
    auto start = chrono::high_resolution_clock::now();  /// KOD NALEŻY WPISAĆ W 30 SKEUND, ZACZYNAMY MIERZYĆ CZAS
    do {
        try {
            input = User_Interaction::picking_something(code);
        }
        catch (const Wrong_Input &wrong_input) {
            input = -1;
            cout << "AN EXCEPTION WAS THROWN: " << wrong_input.what() << endl;
        }
    }
    while(input == -1);

    auto finish = chrono::high_resolution_clock::now();
    auto difference = chrono::duration_cast<chrono::seconds>(finish - start);
    if(difference.count() >= 30) {
        cout << "TRANSACTION FAILED\nYOU'VE EXCEEDED TWO MINUTES TIME\n";
        return true;
    }
    return false;
}

int BLIK::randomize() {
    default_random_engine generator(chrono::system_clock::now().time_since_epoch().count());
    normal_distribution<double> distribution(0.0, 1.0);
    while(code < 100000 || code > 1000000 || code == 0)
        code = abs(distribution(generator)*1000000); /// LOSUJEMY 6-CYFROWY KOD DO BLIKA
    return code;
}
