#include <iostream>

using namespace std;

int main(){
  cout << "Informe o primeiro numero:\n";

  int primeiroNumero;

  cin >> primeiroNumero;

  cout << "Informe o segundo numero:\n";

  int segundoNumero;

  cin >> segundoNumero;

  cout << "Informe o terceiro valor:\n";

  int terceiroValor;

  cin >> terceiroValor;

  float media = (primeiroNumero + segundoNumero + terceiroValor)/3;

  cout << "\nMédia: " << media;
}