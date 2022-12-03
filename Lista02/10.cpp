#include <iostream>

using namespace std;

int main()
{
    float numeros[4] = {};

    srand((unsigned int)time(NULL));

    for (int i = 0; i < 4; i++)
    {
        numeros[i] = (float(rand()) / float(RAND_MAX)) * (rand() % 100);
        cout << numeros[i] << endl;
    }

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (i == j)
                continue;

            if (numeros[i] > numeros[j])
            {
                float aux = numeros[i];
                numeros[i] = numeros[j];
                numeros[j] = aux;
            }
        }
    }

    for (int i = 0; i < 4; i++)
    {
        cout << numeros[i] << " ";
    }

    return 0;
}