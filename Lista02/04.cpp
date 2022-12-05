#include <iostream>

using namespace std;

struct Espectador
{
    int idade;
    int opniao;
};

float porcentagem(int valorTotal, int valorParcial)
{
    return (valorParcial * 100) / valorTotal;
}

int main()
{
    int espectadores;
    cout << "Insira a quantidade de espectadores: ";
    cin >> espectadores;

    int contador = 0;

    int mediaIdades = 0;

    int opnioesRegulares = 0;
    int opnioesBoas = 0;
    int opnioesExcelentes = 0;

    while (contador < espectadores)
    {
        int idade, opniao;

        cout << "Insira a idade do espectador " << contador + 1 << ": ";
        cin >> idade;

        cout << "Insira a opniao do espectador " << contador + 1 << ": ";
        cin >> opniao;

        mediaIdades += idade;

        switch (opniao)
        {
        case 3:
            opnioesExcelentes += 1;
            break;

        case 2:
            opnioesBoas += 1;
            break;

        case 1:
            opnioesRegulares += 1;
            break;
        }

        contador += 1;
    }

    mediaIdades /= espectadores;

    cout << "A media das idades dos espectadores é de: " << mediaIdades << endl;
    cout << "A porcentagem das opnioes excelentes em relação ao total é de: "
    << porcentagem(espectadores, opnioesExcelentes) << endl;
    cout << "A porcentagem das opnioes boas em relação ao total é de: "
    << porcentagem(espectadores, opnioesBoas) << endl;
    cout << "A porcentagem das opnioes regulares em relação ao total é de: "
    << porcentagem(espectadores, opnioesRegulares) << endl;
}