#include <iostream>

using namespace std;

class Pessoa {
    public:
        string nome;
        static int contador;

        Pessoa(){}

        Pessoa(string nome) {
            this->nome = nome;
        }

        // Metódos estaticos só acessam atributos estaticos
        static void numeroPessoas() {
            cout << contador << endl;
        }
};

int Pessoa::contador = 0;

int main() {
    Pessoa p1("Jefferson");
    Pessoa p2("Eduardo");

    cout << p1.nome << endl;
    cout << p2.nome << endl;

    cout << Pessoa::contador << endl;

    // A varival estática é a mesma para todas as instancias da classe
    p1.contador = 10;
    
    cout << Pessoa::contador << endl;

    return 0;
}
