//
// Created by Josiney Junior on 01/10/22.
//
#define _USE_MATH_DEFINES

#include <cmath>

#include <iostream>
#include <string>

using namespace std;

int verifyInput() {
    bool isValid = cin.good();

    return isValid;
}

int main() {
    int seconds;
    cout << "Insira o tempo em segundos:" << endl;
    cin >> seconds;
    int inputIsValid = verifyInput();
    if (!inputIsValid) {
        cout << "Entrada de valor não é válida!" << endl;
        return 0;
    }

    int minutes = 0;
    while (seconds >= 60) {
        seconds -= 60;
        minutes += 1;
    }
    string secondsToString = seconds < 10 ? "0" + to_string(seconds) : to_string(seconds);

    int hours = 0;
    while (minutes >= 60) {
        minutes -= 60;
        hours += 1;
    }
    string minutesToString = minutes < 10 ? "0" + to_string(minutes) : to_string(minutes);
    string hoursToString = hours < 10 ? "0" + to_string(hours) : to_string(hours);

    string formattedHours = hoursToString + ":" + minutesToString + ":" + secondsToString;
    cout << formattedHours;
}