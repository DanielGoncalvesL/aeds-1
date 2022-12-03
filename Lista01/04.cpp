#define _USE_MATH_DEFINES

#include <cmath>#include <iostream>

using namespace std;

int verifyInput() {
    bool isValid = cin.good();

    return isValid;
}

int main() {
    double squareSize;
    cout << "Insira o tamanho do lado do quadrado:" << endl;
    cin >> squareSize;
    int inputIsValid = verifyInput();
    if (!inputIsValid) {
        cout << "Entrada de valor não é válida!" << endl;
        return 0;
    }

    double squareArea = pow(squareSize, 2);
    cout << "A área do quadrado é:" << endl;
    cout << squareArea << endl;

    double circumferenceArea = M_PI * pow(squareSize / 2, 2);
    cout << "A área da circunferência é:" << endl;
    cout << circumferenceArea << endl;

    double externalCircumferenceArea = squareArea - circumferenceArea;

    cout << "A área do quadro externa ao círculo inscrito nele é:" << endl;
    cout << externalCircumferenceArea << endl;
}