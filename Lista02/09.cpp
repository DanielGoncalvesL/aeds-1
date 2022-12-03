#include <iostream>
#include <string>

using namespace std;

int numeroAleatorio(int menor, int maior) {
  return rand()%(maior-menor+1) + menor;
}

int main(){
  srand((unsigned)time(0));

  int vector[3];

  for (size_t i = 0; i < 3; i++)
  {
    vector[i] = numeroAleatorio(1,30);
  }

  for (size_t i = 0; i < 3; i++)
  {
    for (size_t j = 0; j < 2; j++)
    {
      if (vector[j] > vector[j + 1])
      {
        int aux = vector[j];
        vector[j] = vector[j + 1];
        vector[j + 1] = aux;
      }
    }
  }

  for (size_t i = 0; i < 3; i++)
  {
    cout << vector[i] << " ";
  }
}
