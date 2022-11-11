#include <iostream>
#include <string.h>

using namespace std;

int main(){
  cout << "Informe seu ano de nascimento: (DD/MM/AAAA)" << endl;

  char dataNascimento[10];

  cin >> dataNascimento;

  char *splitData = strtok(dataNascimento, "/");

  int dataNascimentoConvertida[3];

  for (size_t i = 0; i < 3; i++)
  {
    dataNascimentoConvertida[i] = strtol(splitData, NULL, 10);

    splitData = strtok(NULL, "/");
  }

  cout << "Informe a data atual: (DD/MM/AAAA)" << endl;

  char dataAtual[10];

  cin >> dataAtual;

  splitData = strtok(dataAtual, "/");

  int dataAtualConvertida[3];

  for (size_t i = 0; i < 3; i++)
  {
    dataAtualConvertida[i] = strtol(splitData, NULL, 10);

    splitData = strtok(NULL, "/");
  }

  int diffAnos;

  if(dataNascimentoConvertida[0] > dataAtualConvertida[0] &&
  dataNascimentoConvertida[1] <= dataAtualConvertida[1]){

    diffAnos = dataAtualConvertida[2] - dataNascimentoConvertida[2] - 1;
  }else{
    diffAnos = dataAtualConvertida[2] - dataNascimentoConvertida[2];
  }

  cout << "Sua idade é: " << diffAnos << " anos";
}
