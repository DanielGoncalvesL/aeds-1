#include <iostream>

using namespace std;

int main(){
  cout << "Informe o numero de alunos: \n";

  int numeroAlunos;

  cin >> numeroAlunos;

  for (size_t i = 0; i < numeroAlunos; i++)
  {
    int notaTotal = 0;

    for (size_t j = 0; j < 3; j++)
    {
      cout << "\nInforme a nota da prova " << j+1 << " do aluno " << i + 1 << ": ";

      int nota;

      cin >> nota;

      notaTotal = notaTotal + nota;
    }
    
    cout << "\nNota total: " << notaTotal;
  }
}