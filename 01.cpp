#include <iostream>

using namespace std;

int main(){
  cout << "Digite um numero:" << endl;

  int number;

  cin >> number;

  cout << "Sucessor: " << (number + 1) << endl << "Antecessor: " << number - 1;
}