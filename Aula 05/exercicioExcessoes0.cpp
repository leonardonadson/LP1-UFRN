#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> numeros;
    int valor, indice;

    cout << "Digite 5 numeros: " << endl;
    for (int i = 0; i < 5; i++) {
        cout << "Digite o numero " << i << ": ";
        cin >> valor;
        numeros.push_back(valor);
    }

    cout << "Buscando no vetor" << endl << "Digite um indice: ";
    cin >> indice;

    try {
        cout << "Numero: " << numeros.at(indice) << endl;

    } catch (const out_of_range& e) {
        cout << "Excecao capturada: " << e.what() << endl;
    }

    return 0;
}