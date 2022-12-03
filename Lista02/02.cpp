#include <iostream>

using namespace std;

int main()
{
    int idade;
    int maior50;
    int menor21;
    while (idade != -1)
    {
        cin >> idade;
        if (idade > 50)
        {
            maior50 += 1;
        }

        if (idade < 21)
        {
            menor21 += 1;
        }
    }

    cout << "Pessoas com menos de 21 anos: " << menor21 << endl;
    cout << "Pessoas com mais de 50 anos: " << maior50 << endl;

    return 0;
}