#include <iostream>
#include <string>

using namespace std;

int main(){
  int numeroAlunos = 15;

  string nomes[numeroAlunos];
  int prova1[numeroAlunos], prova2[numeroAlunos], somaTotal = 0;
  float mediaAluno[numeroAlunos];

  for (size_t i = 0; i < numeroAlunos; i++)
  {
    cout << "\nInforme o nome do " << i + 1 << "° aluno: ";
    cin >> nomes[i];

    cout << "Informe a nota da PR1: ";
    cin >> prova1[i];

    cout << "Informe a nota da PR2: ";
    cin >> prova2[i];

    int soma = prova1[i] + prova2[i];

    mediaAluno[i] = (float) soma/2;

    somaTotal = somaTotal + soma; 
  }

  for (size_t i = 0; i < numeroAlunos; i++)
  {
    cout << "\nNome do " << i + 1 << "° aluno: " << nomes[i] 
      << "\nNota da PR1: " << prova1[i] << "\nNota da PR2: " << prova2[i]
      << "\nMedia do aluno: " << mediaAluno[i] << "\n\n";
  }

  cout << "Media da turma: " << (float) somaTotal/(numeroAlunos * 2);
}