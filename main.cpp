#include <iostream>
#include "Automat.h"

using namespace std;

void hello(Automat & MACHINE){
    int choice;
    while(true) {
        cout << "WELCOME IN OUR MACHINE!\n";
        if(MACHINE.is_empty()) {
            cout << "The machine is empty! Wait for next delivery :(\n";
            break;
        }
        else {
            cout << "Press 1 to buy something\nPress 2 to end the transaction\n";
            cin >> choice;
            if (choice == 1) {
                MACHINE.print_an_offer(); ///NA POCZĄTEK POKAZUJEMY KLIENTOWI OFERTĘ NAPOJÓW
                MACHINE.transaction(); ///PRZECHODZIMY DO TRANSAKCJI
            }
            else if (choice == 2){
                cout << "Are you sure that you want to leave?\n";
                break;
            }
            else {
                cout << "Wrong choice! Pick the drink one more time\n";
                continue;
            }
        }
    }
}

int main() {
    Automat MACHINE;
    hello(MACHINE);
    return 0;
}
