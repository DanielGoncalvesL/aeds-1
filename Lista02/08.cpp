#include <iostream>

using namespace std;

int main()
{
    float numeros[3] = {};

    srand((unsigned int)time(NULL));

    int menor;
    for (int i = 0; i < 3; i++)
    {
        numeros[i] = (float(rand()) / float(RAND_MAX)) * (rand() % 100);
        cout << numeros[i] << endl;

        if (i > 0 && numeros[i] < numeros[i - 1])
        {
            menor = i;
        }
    }

    float somaMaiores = 0;
    for (int i = 0; i < 3; i++)
    {
        if (i == menor)
            continue;

        somaMaiores += numeros[i];
    }

    cout << "Menor: " << numeros[menor] << endl;
    cout << "Soma dos maiores: " << somaMaiores << endl;

    return 0;
}