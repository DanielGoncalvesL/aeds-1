//
// Created by Josiney Junior on 01/10/22.
//
#include <iostream>

using namespace std;

int verifyInput() {
    bool isValid = cin.good();

    return isValid;
}

int main() {
    cout << "Insira um número: " << endl;
    double number;
    cin >> number;
    int inputIsValid = verifyInput();
    if (!inputIsValid) {
        cout << "Entrada de valor não é válida!" << endl;
        return 0;
    }

    if (number == 20) {
        cout << "igual a 20";
        return 0;
    }

    if (number > 20) {
        cout << "maior que 20";
        return 0;
    }

    cout << "menor que 20";
}