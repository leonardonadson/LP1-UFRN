#include <iostream>
#include <string>
#include <vector>
#include <memory> // Necessário para std::unique_ptr

// --- CLASSE BASE ---
// A classe Veículo serve como base para outros tipos de veículos.
// Contém atributos e métodos comuns a todos.
class Veiculo {
protected:
    std::string marca;
    std::string modelo;

public:
    // Construtor da classe base.
    Veiculo(const std::string& marca, const std::string& modelo)
        : marca(marca), modelo(modelo) {}

    // Destrutor virtual para garantir a limpeza correta em classes derivadas.
    virtual ~Veiculo() = default;

    // Método para exibir as informações básicas do veículo.
    void exibirInformacoes() const {
        std::cout << "Marca: " << marca << ", Modelo: " << modelo;
    }

    // Getters para permitir que a classe de sistema acesse os dados para atualização.
    std::string getMarca() const { return marca; }
    std::string getModelo() const { return modelo; }

    // Setters para permitir a atualização.
    void setMarca(const std::string& novaMarca) { marca = novaMarca; }
    void setModelo(const std::string& novoModelo) { modelo = novoModelo; }
};

// --- CLASSES DERIVADAS ---

// A classe Carro herda de Veiculo e adiciona suas próprias especificidades.
class Carro : public Veiculo {
private:
    int numeroPortas;

public:
    // O construtor de Carro chama o construtor da classe base Veiculo.
    Carro(const std::string& marca, const std::string& modelo, int portas)
        : Veiculo(marca, modelo), numeroPortas(portas) {}

    // Método que exibe informações do carro, reutilizando o método da superclasse.
    void exibirInformacoesCarro() const {
        Veiculo::exibirInformacoes(); // Chama o método da classe base.
        std::cout << ", Portas: " << numeroPortas << std::endl;
    }
    
    // Getter e Setter específico de Carro
    int getNumeroPortas() const { return numeroPortas; }
    void setNumeroPortas(int portas) { numeroPortas = portas; }
};

// A classe Moto também herda de Veiculo.
class Moto : public Veiculo {
private:
    int cilindrada;

public:
    // O construtor de Moto também chama o construtor da classe base.
    Moto(const std::string& marca, const std::string& modelo, int cc)
        : Veiculo(marca, modelo), cilindrada(cc) {}

    // Método que exibe informações da moto.
    void exibirInformacoesMoto() const {
        Veiculo::exibirInformacoes(); // Chama o método da classe base.
        std::cout << ", Cilindrada: " << cilindrada << "cc" << std::endl;
    }
    
    // Getter e Setter específico de Moto
    int getCilindrada() const { return cilindrada; }
    void setCilindrada(int cc) { cilindrada = cc; }
};

// --- CLASSE DE CONTROLE (CRUD) ---
// Gerencia a coleção de veículos.
class SistemaVeiculos {
private:
    // Usamos um vetor de ponteiros inteligentes para gerenciar a memória
    // e permitir o polimorfismo (armazenar Carros e Motos em uma lista de Veiculos).
    std::vector<std::unique_ptr<Veiculo>> veiculos;

public:
    // C - CREATE: Adiciona um novo carro ao sistema.
    void adicionarCarro(const std::string& marca, const std::string& modelo, int portas) {
        veiculos.push_back(std::make_unique<Carro>(marca, modelo, portas));
        std::cout << "Carro " << marca << " " << modelo << " adicionado ao sistema.\n";
    }

    // C - CREATE: Adiciona uma nova moto ao sistema.
    void adicionarMoto(const std::string& marca, const std::string& modelo, int cc) {
        veiculos.push_back(std::make_unique<Moto>(marca, modelo, cc));
        std::cout << "Moto " << marca << " " << modelo << " adicionada ao sistema.\n";
    }

    // R - READ: Lista todos os veículos cadastrados.
    void listarVeiculos() const {
        std::cout << "\n--- Lista de Veiculos Cadastrados ---\n";
        if (veiculos.empty()) {
            std::cout << "Nenhum veiculo cadastrado.\n";
            return;
        }
        for (size_t i = 0; i < veiculos.size(); ++i) {
            std::cout << "Indice " << i << ": ";
            // Tenta converter o ponteiro de Veiculo para Carro.
            if (Carro* carro = dynamic_cast<Carro*>(veiculos[i].get())) {
                carro->exibirInformacoesCarro();
            }
            // Se não for Carro, tenta converter para Moto.
            else if (Moto* moto = dynamic_cast<Moto*>(veiculos[i].get())) {
                moto->exibirInformacoesMoto();
            }
        }
        std::cout << "-------------------------------------\n";
    }

    // U - UPDATE: Atualiza os dados de um veículo existente pelo índice.
    bool atualizarVeiculo(size_t indice, const std::string& novaMarca, const std::string& novoModelo) {
        if (indice >= veiculos.size()) {
            std::cout << "Erro: Indice invalido.\n";
            return false;
        }
        veiculos[indice]->setMarca(novaMarca);
        veiculos[indice]->setModelo(novoModelo);
        std::cout << "Veiculo no indice " << indice << " atualizado.\n";
        return true;
    }


    // D - DELETE: Remove um veículo do sistema pelo índice.
    void excluirVeiculo(size_t indice) {
        if (indice >= veiculos.size()) {
            std::cout << "Erro: Indice invalido.\n";
            return;
        }
        // Remove o elemento do vetor. O unique_ptr gerencia a deleção do objeto.
        veiculos.erase(veiculos.begin() + indice);
        std::cout << "Veiculo no indice " << indice << " excluido com sucesso.\n";
    }
};


// --- FUNÇÃO PRINCIPAL (MAIN) ---
// Demonstra o uso do sistema.
int main() {
    SistemaVeiculos sistema;

    // CREATE: Adicionando veículos ao sistema.
    std::cout << ">>> Adicionando veiculos...\n";
    sistema.adicionarCarro("Volkswagen", "Gol", 4);
    sistema.adicionarMoto("Honda", "CB 500", 500);
    sistema.adicionarCarro("Fiat", "Mobi", 4);

    // READ: Listando os veículos.
    sistema.listarVeiculos();

    // UPDATE: Atualizando um veículo.
    std::cout << "\n>>> Atualizando o veiculo no indice 0...\n";
    sistema.atualizarVeiculo(0, "Volkswagen", "Polo");
    sistema.listarVeiculos();
    
    // DELETE: Excluindo um veículo.
    std::cout << "\n>>> Excluindo o veiculo no indice 1...\n";
    sistema.excluirVeiculo(1);
    
    // READ: Listando novamente para ver o resultado.
    sistema.listarVeiculos();

    return 0;
}