#include <iostream>

using namespace std;

int main(){
  cout << "Informe a temperatura em °F:\n";

  int temperatura;

  cin >> temperatura;

  float temperaturaCelsius = (temperatura - 32) * (5/9.0);

  cout << "Temperatura em °C: " << temperaturaCelsius;
}