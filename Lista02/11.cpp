#include <iostream>
#include <string>

using namespace std;

int numeroAleatorio(int menor, int maior) {
  return rand()%(maior-menor+1) + menor;
}

int main(){
  srand((unsigned)time(0));

  int vector[5];

  for (size_t i = 0; i < 5; i++)
  {
    vector[i] = numeroAleatorio(1,30);
  }

  int maior = 0, menor = 0;

  for (size_t i = 0; i < 5; i++)
  {
    if(i == 0){
      maior = vector[0];
      menor = vector[0];
    }

    if(vector[i] > maior){
      maior = vector[i];
    }

    if(vector[i] < menor){
      menor = vector[i];
    }
  }

  cout << "\nMaior: " << maior
    << "\nMenor: " << menor;
}
