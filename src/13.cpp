#include <iostream>

using namespace std;

int main(){
  cout << "Informe o valor A: ";

  int valorA;

  cin >> valorA;

  cout << "\nInforme o valor B: ";

  int valorB;

  cin >> valorB;

  int auxiliar = valorB;

  valorB = valorA;

  valorA = auxiliar;

  cout << "\nValor A trocado: " << valorA << "\nValor B trocado: " << valorB;
}