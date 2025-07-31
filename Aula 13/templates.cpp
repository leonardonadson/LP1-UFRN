#include <iostream>
#include <string>

using namespace std;

// Template Animal
//  Use templates quando você precisa da mesma lógica para múltiplos tipos de dados.
//  Aqui, a classe Animal pode armazenar qualquer tipo como identificador.
template <typename T>
class Animal {
public:
    T identificador;
};

// Classe Identificador usada como tipo genérico em Animal<T>
class Identificador {
public:
    string head = "sfsfa";
    string payload = "78965";
    string signature = "98gfds7fd";
};

// Classe base para animais com polimorfismo
class AnimalBase {
public:
    virtual void emitirSom() const = 0;
    virtual ~AnimalBase() = default;
};

// Cachorro herda de AnimalBase
class Cachorro : public AnimalBase {
public:
    void emitirSom() const override {
        cout << "Au Au!\n";
    }
};

// Gato herda de AnimalBase
class Gato : public AnimalBase {
public:
    void emitirSom() const override {
        cout << "Miau!\n";
    }
};

// PetShop genérico
//  Use templates quando você precisa da mesma lógica para múltiplos tipos de dados.
//  O PetShop funciona com qualquer classe de animal que tenha emitirSom().
template <typename T>
class PetShop {
public:
    void banhoETosa(const T& animal) {
        cout << "Realizando banho e tosa...\n";
        animal.emitirSom();
    }
};

// Clínica Veterinária genérica
//  Use templates quando você precisa da mesma lógica para múltiplos tipos de dados.
//  A clínica veterinária funciona para qualquer tipo de animal.
template <typename T>
class ClinicaVeterinaria {
public:
    void realizarExame(const T& animal) {
        cout << "Realizando exame no animal...\n";
        animal.emitirSom();
    }
};

int main()
{
    // --- Parte 1: Animal com Identificador ---
    Animal<Identificador> a;  // Aqui o template Animal é usado com Identificador
    Identificador id;
    a.identificador = id;

    cout << "Identificador do animal: "
         << a.identificador.head << " "
         << a.identificador.payload << " "
         << a.identificador.signature << "\n\n";

    // --- Parte 2: PetShop e Clínica ---
    Cachorro dog;
    Gato cat;

    ClinicaVeterinaria<Cachorro> vetDog; // Template usado com Cachorro
    vetDog.realizarExame(dog);

    PetShop<Gato> petShopCat;            // Template usado com Gato
    petShopCat.banhoETosa(cat);

    return 0;
}
