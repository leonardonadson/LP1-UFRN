#include <iostream>
using namespace std;

int main() {
    int opcao;

    cout << "Digite uma opção: ";
    cin >> opcao;

    switch (opcao) {
        case 1:
            cout << "Opção 1" << endl;
            break;
        case 2:
            cout << "Opção 2" << endl;
            break;
        default:
            cout << "Outra opção" << endl;
            break;
    }
    return 0;
}