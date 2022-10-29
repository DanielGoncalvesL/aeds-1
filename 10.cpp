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
    int time;
    cout << "Insira o tempo em horas:" << endl;
    cin >> time;
    int inputIsValid = verifyInput();
    if (!inputIsValid) {
        cout << "Entrada de valor não é válida!" << endl;
        return 0;
    }

    int averageSpeed;
    cout << "Insira a velocidade média em km/h:" << endl;
    cin >> averageSpeed;
    inputIsValid = verifyInput();
    if (!inputIsValid) {
        cout << "Entrada de valor não é válida!" << endl;
        return 0;
    }

    int distance = time * averageSpeed;
    cout << "Ele percorreu uma distância de: " << distance << " quilometros" << endl;

    double fuelSpent = distance / 12;
    cout << "Gastou " << fuelSpent << " litro(s) de combustivel" << endl;
}
