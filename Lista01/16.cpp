#include <iostream>

using namespace std;

int verifyInput() {
    bool isValid = cin.good();

    return isValid;
}

int main() {
    cout << "Insira um valor:" << endl;
    double value;
    cin >> value;
    int inputIsValid = verifyInput();
    if (!inputIsValid) {
        cout << "Entrada de valor não é válida!" << endl;
        return 0;
    }

    double readjustment = value + (value * 0.1);
    cout << "Reajuste de 10%: " << readjustment << endl;
}