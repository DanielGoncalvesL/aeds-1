//
// Created by Josiney Junior on 01/10/22.
//

#include <iostream>

using namespace std;

int verifyInput();

int main() {
    cout << "Insira um número inteiro:" << endl;
    int number;
    cin >> number;
    int inputIsValid = verifyInput();
    if (!inputIsValid) {
        cout << "Entrada de valor não é válida!" << endl;
        return 0;
    }

    int units = number % 10;
    cout << "Seu numero da unidade é:" << endl;
    cout << units << endl;

    int tens = (number - units) % 100 / 10;
    cout << "Seu número da dezena é:" << endl;
    cout << tens << endl;

    int hundreds = ((number - units - (tens * 10)) % 1000) / 100;
    cout << "Seu número da centena é:" << endl;
    cout << hundreds << endl;

    int doubleNumber = number * 2;
    cout << "O dobro do número é:" << endl;
    cout << doubleNumber << endl;
}

int verifyInput() {
    bool isValid = cin.good();

    return isValid;
}