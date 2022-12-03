#include <iostream>

using namespace std;

int main()
{
    float a, b;

    cout << "Insira o valor do coeficiente a: " << endl;
    cin >> a;

    cout << "Insira o valor do coeficiente b: " << endl;
    cin >> b;

    float raiz = (b * -1) / a;

    cout << "A raiz da equação é: " << raiz;

    return 0;
}