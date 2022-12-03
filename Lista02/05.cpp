#include <iostream>

using namespace std;

float calcularMilimetro(int a, int b){
  return ((float) a/b) * 25.4;
}

int main(){
  int a,b;

  cout << "Informe o valor A: ";
  cin >> a;

  cout << "Informe o valor B: ";
  cin >> b;

  while(b == 0){
    cout << "Informe o valor de B novamente: ";
    cin >> b;
  }

  cout << "\nNumero convertido: " << calcularMilimetro(a,b);
}
