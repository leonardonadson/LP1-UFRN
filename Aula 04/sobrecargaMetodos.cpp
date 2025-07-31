#include <iostream>

using namespace std;

// Sobrecarca com valor padrão
void imprimir(int x = 0) {
    cout << "Inteiro: " << x << endl;
}

void imprimir(double x) {
    cout << "Double: " << x << endl;
}

void imprimir(string x) {
    cout << "String: " << x << endl;
}

int main() {
    imprimir(10);
    imprimir(3.14);
    imprimir("Olá");
    return 0;
}
