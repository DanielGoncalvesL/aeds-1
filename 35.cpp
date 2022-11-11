#include <iostream>
#include <string>

using namespace std;

int main(){
  int somaIdade = 0;

  int nota1 = 0, nota2 = 0, nota3 = 0;

  for (size_t i = 0; i < 20; i++){
    cout << "\nInforme a idade do " << i+1  << "° espectador: ";

    int idade;

    cin >> idade;

    cout << "\nInforme a sua avaliacao do filme (1 - Regular, 2 - Bom, 3 - Excelente): ";

    int avaliacao;

    cin >> avaliacao;

    while(avaliacao != 1 && avaliacao != 2 && avaliacao != 3){
      cout << "\nInforme a sua avaliacao do filme novamente(1 - Regular, 2 - Bom, 3 - Excelente): ";

      cin >> avaliacao;
    }

    somaIdade = somaIdade + idade;

    if(avaliacao == 1){
      nota1 = nota1 + avaliacao;
    }else if(avaliacao == 2){
      nota2 = nota2 + avaliacao;
    }else if(avaliacao == 3){
      nota3 = nota3 + avaliacao;
    }
  }

  cout << "\nMedia das idades: " << somaIdade/20 << endl;

  cout << "\nPercetagem das pessoas que responderam 1: " << (nota1 * 100)/20 <<
          "\nPercetagem das pessoas que responderam 2: " << (nota2 * 100)/20 <<
          "\nPercetagem das pessoas que responderam 3: " << (nota3 * 100)/20;
}
