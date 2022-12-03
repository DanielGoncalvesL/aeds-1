#include <iostream>

using namespace std;

int main(){
  float salario, prestacao;

  cout << "Informe o seu salario: ";

  cin >> salario;

  cout << "Informe a prestacao: \n";

  cin >> prestacao;

  float diffPercentual = (prestacao * 100)/salario;

  if(diffPercentual > 20){
    cout << "\nEmprestimo não pode ser concecido!";
  }else {
    cout << "\nEmprestimo pode ser concecido!";
  }
}
