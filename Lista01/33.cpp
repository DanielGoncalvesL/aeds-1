#include <iostream>
#include <string>

using namespace std;

int main(){
  int soma = 0;

  for (size_t i = 0; i < 15; i++){
    cout << "\nInforme o nome do " << i+1  << "° aluno: ";

    string nome;

    cin >> nome;

    cout << "\nInforme a nota da PR1: ";

    int nota1;

    cin >> nota1;

    cout << "\nInforme a nota da PR2: ";

    int nota2;

    cin >> nota2;

    float media = (nota1 + nota2)/2;

    cout << "\nNome do aluno: " << nome << 
    " - Media das notas: " << media << endl;

    soma = soma + (nota1 + nota2);
  }

  cout << "\nMedia da turma: " << soma/30;
}
