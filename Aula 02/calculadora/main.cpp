#include <iostream>
#include "operadores.h"

using namespace std;

/*
Comando para compilar:

g++ -Wall -Wextra -g3 main.cpp operadores.cpp -o output/main.exe

*/

int main(){
    int parar = 0;
    do{
        int opcao;
        cout << "Calculadora - Simples " << endl;
        cout << endl << "Selecione uma opção:" << endl;
        cout << endl << "1 - Soma" << endl;
        cout << "2 - Subtracao" << endl;
        cout << "3 - Multiplicacao" << endl;
        cout << "4 - Divisao" << endl;
        cout << "5 - Sair" << endl;

        cin >> opcao;

        float a, b;

        switch (opcao)
        {
        case 1:
            
            cout << "Digite o primeiro valor: " << endl;
            cin >> a;
            cout << "Digite o segundo valor: " << endl;
            cin >> b;
            cout << "Soma: " << soma(a, b) << endl;
            break;
        
        case 2:
            cout << "Digite o primeiro valor: " << endl;
            cin >> a;
            cout << "Digite o segundo valor: " << endl;
            cin >> b;
            cout << "Subtracao: " << subtracao(a, b) << endl;
            break;
        
        case 3:
            cout << "Digite o primeiro valor: " << endl;
            cin >> a;
            cout << "Digite o segundo valor: " << endl;
            cin >> b;
            if (b == 0)
            {
                cout << "Nao pode dividir por 0" << endl;
                break;
            }
            cout << "Multiplicacao: " << multiplicacao(a, b) << endl;
            break;
        
        case 4:
            cout << "Digite o primeiro valor: " << endl;
            cin >> a;
            cout << "Digite o segundo valor: " << endl;
            cin >> b;
            cout << "Divisao: " << divisao(a, b) << endl;
            break;
        
        case 5:
            parar = 1;
            break;

        default:
            break;
        }


    }while(parar == 0);
}
