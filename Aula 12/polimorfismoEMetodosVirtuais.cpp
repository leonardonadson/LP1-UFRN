#include <iostream>

using namespace std;

class Animal {
public:
    // Construtor da classe Animal
    Animal(){
        cout << "Construtor da classe Animal" << endl;
    };

    // Método virtual que pode ser sobrescrito por classes derivadas
    virtual void emitarSom() {
        cout << "Animal emitindo som" << endl;
    }

    // Método virtual puro, tornando Animal uma classe abstrata
    virtual void existir()  = 0; 
};

class Gato : public Animal {
public:
    // Construtor da classe Gato
    Gato(){
        cout << "Construtor da classe Gato" << endl;
    };
    
    // Sobrescrevendo o método emitarSom da classe Animal
    void emitarSom() override {
        cout << "Gato emitindo som" << endl;
    }

    // Método específico da classe Gato
    void miar() {
        cout << "Miau!" << endl;
    }

    void ronronar() {
        cout << "ronron" << endl;
    }
    
    // Implementação do método virtual puro da classe Animal
    void existir() override {
        cout << "Gato existindo" << endl;
    }

};



int main() {

    Animal* g = new Gato();

    Gato ga;

    //Animal não possui o metodo miar, então não pode ser chamado através do ponteiro g
    //g -> miar();

    // Mas podemos chamar o método miar através do objeto ga
    ga.miar();

    //Animal possui o método emitarSom, que foi sobrescrito na classe Gato
    g -> emitarSom();

    return 0;
}