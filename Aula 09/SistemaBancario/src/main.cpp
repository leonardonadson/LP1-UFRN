#include "conta.h"
#include <iostream>

using namespace std;

int main() {
    try {
        Conta conta1(101, "Cliente A", 2500.00);
        Conta conta2(102, "Cliente B", 800.00);

        cout << "--- Saldo Inicial ---" << endl;
        cout << conta1 << endl;
        cout << conta2 << endl;

        double valorTransferencia = 500.00;
        
        conta2 = conta1 - valorTransferencia;

        cout << "\n--- Saldo Final ---" << endl;
        cout << conta1 << endl;
        cout << conta2 << endl;

    } catch (const exception& e) {
        cerr << "Erro: " << e.what() << endl;
        return 1;
    }

    return 0;
}