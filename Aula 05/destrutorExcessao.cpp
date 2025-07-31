#include <iostream>

#include <vector>

using namespace std;

struct Pessoa
{
    int idade;


    void setIdade(int idade) {
        if (idade < 0) {
            throw invalid_argument("Idade inválida");
        }
        this->idade = idade;
    }

    ~Pessoa() {
        cout << "Destruindo Objeto com idade: " << this->idade << endl;
    }
};

int main() {
    
    try {
        Pessoa p;

        p.setIdade(-30);

        throw invalid_argument("Argumento invaldido");
    } catch (const exception& e) {
        cout << "Mensagem do erro: " << e.what() << endl;
    }

    return 0;
}