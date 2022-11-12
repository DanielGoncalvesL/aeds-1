#define _USE_MATH_DEFINES

#include <cmath>
#include <iostream>

using namespace std;

int verifyInput() {
    bool isValid = cin.good();

    return isValid;
}

int main() {
    double angle;
    cout << "Insira o valor do ângulo em graus:" << endl;
    cin >> angle;
    int inputIsValid = verifyInput();
    if (!inputIsValid) {
        cout << "Entrada de valor não é válida!" << endl;
        return 0;
    }

    double radAngle = angle * M_PI / 180;
    cout << "Seu valor em radianos é:" << endl;
    cout << radAngle << endl;
}