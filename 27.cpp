#include <iostream>

using namespace std;

int main(){
  int valor;

  cout << "Informe um valor: ";

  cin >> valor;

  if(valor <= 0 ){
    cout << "Programa encerrado!";
  }else {
    int soma = 0, contador = 0;

    while(valor > 0 ){
      soma = soma + valor;

      contador = contador + 1;

      cout << "\nInforme outro valor: ";

      cin >> valor;
    }

    cout << "\nValor total da soma: " << soma << " Média dos valores: " << soma/contador << " Quantidade de valores lidos: " << contador;
  }
}
