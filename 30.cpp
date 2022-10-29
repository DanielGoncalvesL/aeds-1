//
// Created by Josiney Junior on 04/10/22.
//
#include <iostream>

using namespace std;

int verifyInput() {
    bool isValid = cin.good();

    return isValid;
}

int main() {
    cout << "Insira a idade da pessoa:" << endl;
    int age;
    cin >> age;
    int inputIsValid = verifyInput();
    if (!inputIsValid) {
        cout << "Entrada de valor não é válida!" << endl;
        return 0;
    }

    string eleitoralClass = "Não-eleitor";

    if (age >= 18 && age <= 65) {
        eleitoralClass = "Eleitor obrigatório";
    }

    if ((age >= 16 && age < 18) || age > 65) {
        eleitoralClass = "Eleitor facultativo";
    }

    cout << "A class eleitoral dessa pessoal é: " << eleitoralClass << endl;
}