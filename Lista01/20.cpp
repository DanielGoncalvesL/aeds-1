#include <iostream>

using namespace std;

int verifyInput() {
    bool isValid = cin.good();

    return isValid;
}

int main() {
    cout << "Insira o valor do primeiro número: " << endl;
    int number1;
    cin >> number1;
    int inputIsValid = verifyInput();
    if (!inputIsValid) {
        cout << "Entrada de valor não é válida!" << endl;
        return 0;
    }

    cout << "Insira o valor do segundo número: " << endl;
    int number2;
    cin >> number2;
    inputIsValid = verifyInput();
    if (!inputIsValid) {
        cout << "Entrada de valor não é válida!" << endl;
        return 0;
    }

    int sum = number1 + number2;
    if (sum > 10) {
        cout << sum;
        return 0;
    }
}