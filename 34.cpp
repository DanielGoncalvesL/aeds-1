//
// Created by Josiney Junior on 04/10/22.
//
#include <iostream>

using namespace std;

int main() {
    int weight[20];
    int age[20];

    int count = 0;

    do {
        cout << "Insira o peso da pessoa: " << endl;
        cin >> weight[count];

        cout << "Insira a idade da pessoa: " << endl;
        cin >> age[count];

        ++count;
    } while (count < 20);

    float weight10Average = 0.0;
    float weight20Average = 0.0;
    float weight30Average = 0.0;
    float weight31Average = 0;

    float ageAverage = 0;
    for (int i = 0; i < 20; i++) {
        int personAge = age[i];

        if(personAge <= 10){
            weight10Average += weight[i];
            continue;
        }

        if(personAge > 10 && personAge <= 20){
            weight20Average += weight[i];
            continue;
        }

        if(personAge > 20 && personAge <= 30){
            weight30Average += weight[i];
            continue;
        }

        weight31Average += weight[i];
    }

    weightAverage /= 20.0;
    ageAverage /= 20.0;
}