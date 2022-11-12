//
// Created by Josiney Junior on 11/11/22.
//#include <iostream>

using namespace std;

int main()
{
    int limiteInferior, limiteSuperior, valorNoIntervalo;

    cout << "Informe o valor do limite inferior: ";
    cin >> limiteInferior;

    cout << "Informe o valor do limite superior: ";
    cin >> limiteSuperior;

    if (limiteInferior % 2 == 0)
        limiteInferior += 2;
    else
        limiteInferior += 1;

    float somatorio = 0;
    for (valorNoIntervalo = limiteInferior; valorNoIntervalo <= limiteSuperior - 1; valorNoIntervalo += 2)
    {
        if(valorNoIntervalo % 2 == 0)
            cout << valorNoIntervalo << endl;
        somatorio += valorNoIntervalo;
    }

    cout << "Somatório: " << somatorio;

    return 0;
}