//
// Created by Josiney Junior on 04/10/22.
//
#include <iostream>

using namespace std;

int main() {
    int number = 0;
    int mostNumber = 0;
    int leastNumber = -1;

    while (number >= 0) {
        cin >> number;
        if (number > mostNumber) {
            mostNumber = number;
        }

        if (leastNumber == -1 || (number < leastNumber && number >= 0)) {
            leastNumber = number;
        }
    }

    cout << "Maior número inserido: " << mostNumber << endl;
    cout << "Menor número inserido: " << leastNumber << endl;
}