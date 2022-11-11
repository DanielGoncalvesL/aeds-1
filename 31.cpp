#include <iostream>

using namespace std;

int main(){
  int valor;

  cout << "Informe um valor: ";

  cin >> valor;

  if(valor == 0){
    cout << "Programa encerrado!";
  }else {
    int soma = 0, contador = 0;

    while(valor != 0){
      if(valor % 3 == 0){
        soma = soma + valor;

        contador = contador + 1;
      }

      cout << "Informe outro valor: ";

      cin >> valor;
    }

    cout << "A média dos valores multiplos de 3 sao: " << soma/contador;
  }
}
