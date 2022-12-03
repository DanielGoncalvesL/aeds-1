#include <iostream>

using namespace std;

int numeroAleatorio(int menor, int maior) {
  return rand()%(maior-menor+1) + menor;
}

int main(){
  srand((unsigned)time(0));

  int vector[8];

  int vectorSize = sizeof(vector)/sizeof(vector[0]);

  for (size_t i = 0; i < vectorSize; i++)
  {
    vector[i] = numeroAleatorio(1,10);
  }

  cout << "Informe o numero a ser buscado: ";

  int numeroBuscado;

  cin >> numeroBuscado;

  for (size_t i = 0; i < vectorSize; i++)
  {
    if(vector[i] == numeroBuscado){
      cout << "O numero " << numeroBuscado 
        << " foi encontrado" << "\nPosicao no vetor: " << i;
    }
  }
  
}