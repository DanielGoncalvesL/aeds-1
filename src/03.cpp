#include <iostream>
#include <cmath>

using namespace std;

float calcularPerimetro(float lado, float altura) {
  float perimetroCalculado = (lado * 2) + (altura * 2); 

  return perimetroCalculado;
}

int main(){
  cout << "Informe o lado do retangulo(cm):\n";

  float lado;

  cin >> lado;

  while(lado <= 0) {
    cout << "Informe o lado do retangulo(cm) novamente:\n";
    
    cin >> lado;
  }

  cout << "Informe a altura do retangulo(cm):\n";

  float altura;

  cin >> altura;

  while(altura <= 0) {
    cout << "Informe a altura do retangulo(cm) novamente:\n";

    cin >> altura;
  }

  cout << "\nPerimetro: " << calcularPerimetro(lado, altura) << "cm\n\n";

  cout << "Diagonal: " << pow((pow(lado, 2)) + (pow(altura, 2)), 0.5) << "cm\n\n";

  cout << "Area: " << lado * altura << " cm²";
}