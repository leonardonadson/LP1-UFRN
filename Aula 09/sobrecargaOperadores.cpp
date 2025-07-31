#include <iostream>

using namespace std;

class Pessoa{
    public:
        int idade;
        Pessoa(int idade){
            this-> idade = idade;
        }

        friend ostream& operator<<(ostream& os, Pessoa& p);

        /*
        Pessoa operator+(int ano){
            return Pessoa(ano + idade);
        }
        */
};

Pessoa operator+(Pessoa& p, int ano){
    return operadorSomaPessoa(ano, p);
}
Pessoa operator+(int ano, Pessoa& p){
    return operadorSomaPessoa(ano, p);
}

Pessoa operadorSomaPessoa(int ano, Pessoa& p){
    return Pessoa(ano + p.idade);
}

ostream& operator<<(ostream& os, Pessoa& p){
    cout << "Idade: "<< p.idade << endl;

    return os;
}


int main(){
    Pessoa p(10);

    Pessoa p2 = p + 1;

    cout << p2.idade << endl;

    return 0;
}