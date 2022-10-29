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
    cout << "Insira o nome:" << endl;
    string name;
    cin >> name;
    int inputIsValid = verifyInput();
    if (!inputIsValid) {
        cout << "Entrada de valor não é válida!" << endl;
        return 0;
    }

    cout << "Insira o sexo:" << endl;
    string gender;
    cin >> gender;
    inputIsValid = verifyInput();
    if (!inputIsValid) {
        cout << "Entrada de valor não é válida!" << endl;
        return 0;
    }

    cout << "Insira a idade:" << endl;
    int age;
    cin >> age;
    inputIsValid = verifyInput();
    if (!inputIsValid) {
        cout << "Entrada de valor não é válida!" << endl;
        return 0;
    }

    if (gender == "feminino" && age < 25) {
        cout << name << " ACEITA" << endl;
        return 0;
    }

    cout << "NAO ACEITA";
}