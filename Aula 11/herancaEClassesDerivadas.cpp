#include <iostream>
#include <string>

// --- Herança e Modificadores de Acesso ---
//
// A herança permite que uma classe (derivada) herde atributos e métodos de outra classe (base).
// Em C++, a visibilidade da herança pode ser definida com modificadores de acesso.
//
// Modificadores de Acesso na Herança (conforme slide 'Modificadores de acesso'):
// - public: Membros 'public' e 'protected' da classe base permanecem acessíveis na derivada.
// - protected: Membros 'public' e 'protected' da classe base se tornam 'protected' na derivada.
// - private: Membros 'public' e 'protected' da classe base se tornam 'private' na derivada.

// Classe Base
class Animal {
public:
    std::string nome;

    // Construtor da classe base
    Animal(const std::string& n) : nome(n) {
        std::cout << "Construtor de Animal chamado." << std::endl;
    }

    // Função para ser usada no polimorfismo
    void fazerSom() {
        std::cout << "Animal fazendo som..." << std::endl;
    }
};

// --- Herança Simples e Construtores ---
//
// Mesmo que a classe 'Gato' não tenha um atributo chamado 'nome' definido diretamente nela,
// é possível acessá-lo, pois 'Gato' herda esse atributo de 'Animal'.
// Assim, a classe derivada 'Gato' tem acesso aos mesmos atributos da classe base.
class Gato : public Animal {
public:
    int idade;

    // --- Como chamar um construtor ---
    //
    // Construtores não são herdados. Para passar informações da classe
    // derivada para a classe base, você deve usar a lista de inicialização do construtor.
    // A sintaxe `Gato(...) : Animal(n)` chama o construtor da classe base 'Animal'.
    Gato(const std::string& n, int i) : Animal(n), idade(i) {
        std::cout << "Construtor de Gato chamado." << std::endl;
    }
};


// --- Ocultação de Nome (Name Hiding) ---
//
// Se uma classe derivada declarar um atributo com o mesmo nome de um atributo
// da classe base, o "atributo da derivada 'esconde' (ou oculta) o da base".
// Esse comportamento é chamado de 'name hiding'.
class Cao : public Animal {
public:
    // Este atributo 'nome' oculta o 'nome' herdado da classe Animal.
    std::string nome;

    Cao(const std::string& nomeBase, const std::string& nomeDerivado) : Animal(nomeBase) {
        this->nome = nomeDerivado;
    }

    void exibirNomes() {
        // Por padrão, ao acessar 'nome', o compilador acessa o membro da classe derivada.
        std::cout << "Nome na classe derivada (Cao): " << nome << std::endl; // Imprime o nome do Cao

        // Se você quiser acessar o nome da classe base, precisa usar uma qualificação de escopo.
        std::cout << "Nome na classe base (Animal): " << Animal::nome << std::endl; // Imprime o nome do Animal
    }
};


// --- Tipos Estáticos e Dinâmicos ---
//
// Permite tratar todos os objetos de uma mesma família de forma igual.
// Se existir as classes 'Gato' e 'Cachorro' que herdam 'Animal',
// então é possível tratar 'Gato' e 'Cachorro' como 'Animal', sem distinção.

void brincarComAnimal(Animal* animal) {
    std::cout << "Brincando com o animal chamado: " << animal->nome << std::endl;
}


// --- Herança Múltipla ---
//
// C++ permite que uma classe herde de duas ou mais classes ao mesmo tempo.
// Ou seja, uma classe derivada pode herdar atributos e métodos de várias classes base.

class Caminhante {
public:
    void andar() {
        std::cout << "Andando..." << std::endl;
    }
};

class Nadador {
public:
    void nadar() {
        std::cout << "Nadando..." << std::endl;
    }
};

// A classe Triatleta herda de Caminhante e Nadador
class Triatleta : public Caminhante, public Nadador {
public:
    void competir() {
        std::cout << "Competindo no triatlo!" << std::endl;
        andar();
        nadar();
    }
};

// --- Problema do Diamante (Diamond Problem) na Herança Múltipla ---
//
// Para evitar ambiguidades no código, como o "problema do losango" (Diamond Problem),
// onde duas superclasses definem o mesmo método e a linguagem não saberia qual usar.
// O problema do losango acontece quando uma subclasse herda de duas superclasses,
// e essas superclasses herdam de uma mesma superclasse base (formando um losango: A -> B, A -> C, B -> D, C -> D).
// C++ resolve isso com herança virtual, mas é um tópico avançado.


int main() {
    std::cout << "--- DEMONSTRACAO DE HERANCA E CONSTRUTORES ---\n";
    Gato gatinho("Frajola", 5);
    std::cout << "Nome do gatinho: " << gatinho.nome << std::endl;
    std::cout << "Idade do gatinho: " << gatinho.idade << std::endl;
    std::cout << "\n";

    std::cout << "--- DEMONSTRACAO DE OCULTACAO DE NOME (NAME HIDING) ---\n";
    Cao dog("Rex (base)", "Pluto (derivado)");
    dog.exibirNomes();
    std::cout << "\n";

    std::cout << "--- DEMONSTRACAO DE TIPOS ESTATICOS E DINAMICOS ---\n";
    // Tipo Estático: é o tipo da variável conforme determinado no código-fonte.
    // É o tipo que o compilador vê quando o código é compilado.
    //
    // Tipo Dinâmico: é o tipo real do objeto no momento da execução, ou seja,
    // o tipo do objeto para o qual a variável aponta.

    Animal* ptrAnimal1 = new Animal("Animal Genérico");
    // Tipo Estático: Animal*
    // Tipo Dinâmico: Animal

    Animal* ptrAnimal2 = new Gato("Mingau", 2);
    // Tipo Estático: Animal*
    // Tipo Dinâmico: Gato

    std::cout << "Ponteiro 1 (ptrAnimal1):\n";
    std::cout << "  - Tipo Estatico: Animal*\n";
    std::cout << "  - Aponta para um objeto do tipo: Animal\n";
    brincarComAnimal(ptrAnimal1);

    std::cout << "\nPonteiro 2 (ptrAnimal2):\n";
    std::cout << "  - Tipo Estatico: Animal*\n";
    std::cout << "  - Aponta para um objeto do tipo: Gato\n";
    brincarComAnimal(ptrAnimal2);
    std::cout << "\n";

    delete ptrAnimal1;
    delete ptrAnimal2;

    std::cout << "--- DEMONSTRACAO DE HERANCA MULTIPLA ---\n";
    Triatleta atleta;
    atleta.competir();
    std::cout << "\n";

    return 0;
}