#include <iostream>

using namespace std;

int main(){
  int numero[10];

  for (int i = 0; i < 10; i++){
    cout << "Informe o " << i + 1 << "° valor:\n";

    cin >> numero[i];
  }

  int contador = 1;

  for (int i = 0; i < 10; i++){

    if(numero[i] > 20){
      float metadeNumero = numero[i]/2.0;

      cout << "\n" << contador << "° numero maior que 20: " << numero[i] << "\nSua metade: " << metadeNumero << "\n";

      contador++;
    }
  }
  
}