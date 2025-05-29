#include <iostream>

using namespace std;

struct Pessoa
{
    string nome;
    int idade;
    float altura;

    void apresentar(){
        cout << "Olá meu nome é " << nome << endl;
    }

    void caracteristicas(){
        cout << "Eu tenho " << idade << " anos e " << altura << " de altura." << endl;
    }

    /*
    Pessoa(string name, int age, float height){
        nome = name;
        idade = age;
        altura = height;
    }
    */

    Pessoa(string nome, int idade, float altura){
        this->nome = nome;
        this->idade = idade;
        this->altura = altura;
    }

    /*
    Pessoa(string nome, int i): nome(nome), idade(i){
        cout << "Construtor executado!" << endl;
    }
    */

};

int main()
{
    /*
    Pessoa p;
    p.nome = "João";
    p.idade = 25;
    
    p.apresentar();
    */

    Pessoa pessoa("João", 25, 1.80);


    pessoa.apresentar();
    pessoa.caracteristicas();

    return 0;
}