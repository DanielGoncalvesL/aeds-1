//
// Created by Josiney Junior on 04/10/22.
//
#include <iostream>

using namespace std;

int main() {
    int age = 0;

    int lessThan21 = 0;
    int greaterThan50 = 0;

    do {
        cin >> age;

        if (age < 21) {
            lessThan21 += 1;
        }

        if (age > 50) {
            greaterThan50 += 1;
        }
    } while (age != -1);

    cout << "Quantidade de idades menores que 21: " << lessThan21 << endl;
    cout << "Quantidade de idades maiores que 50: " << greaterThan50 << endl;
}
