#include <iostream>

using namespace std;

int main(){
  cout << "Informe a medida de arco em graus:\n";

  int graus;

  cin >> graus;

  float radianos = graus * (3.14/180);

  cout << "\nMedida do arco em radianos: " << radianos;
}