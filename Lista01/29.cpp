#include <iostream>

using namespace std;

int main(){
  int valor;

  cout << "Informe um valor: ";

  cin >> valor;

  if(valor % 10 == 0){
    cout << "O número é divísivel por 10 e por 5 e por 2";
  }

  if(valor % 5 == 0 && valor % 10 != 0){
    cout << "O número é divísivel por 5";
  }

  if(valor % 2 == 0 && valor % 5 != 0 && valor % 10 != 0){
    cout << "O número é divísivel por 2";
  }
}
