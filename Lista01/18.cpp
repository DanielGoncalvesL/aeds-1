#include <iostream>

using namespace std;

int verifyInput() {
    bool isValid = cin.good();

    return isValid;
}

int main() {
    cout << "Insira o preço do produto:" << endl;
    double productPrice;
    cin >> productPrice;
    int inputIsValid = verifyInput();
    if (!inputIsValid) {
        cout << "Entrada de valor não é válida!" << endl;
        return 0;
    }

    double discountOf9 = productPrice - (productPrice * 0.09);
    cout << "Preço do produto com um desconto de 9%: " << discountOf9 << endl;
}