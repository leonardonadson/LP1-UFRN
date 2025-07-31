#include <iostream> 
#include <string>  
#include <vector>  

// Classe para representar o cliente do hotel.
class Cliente {
public:
    std::string nome;
    std::string tipo; // Pode ser "VIP" ou "Comum".

    // Construtor para inicializar um objeto Cliente.
    Cliente(const std::string& nome, const std::string& tipo) : nome(nome), tipo(tipo) {}
};

// Classe para representar um quarto do hotel.
class Quarto {
public:
    int numero;
    double precoBase;
    static const double ADICIONAL_LUXO; // Constante de classe para o adicional de luxo.

    // Construtor para inicializar um objeto Quarto.
    Quarto(int numero, double precoBase) : numero(numero), precoBase(precoBase) {}

    // Calcula o preço final da diária com base no tipo de cliente.
    double calcularPrecoFinal(const Cliente& cliente) const {
        double precoFinal = precoBase;
        if (cliente.tipo == "VIP") {
            precoFinal *= 0.90; // Aplica 10% de desconto para clientes VIP.
        }
        return precoFinal;
    }
};

// Inicialização do membro estático constante da classe Quarto.
const double Quarto::ADICIONAL_LUXO = 1.20; // Acréscimo de 20% para quartos de luxo.

// Classe para representar uma reserva no hotel.
class Reserva {
public:
    const Cliente& cliente;
    const Quarto& quarto;
    double valorFinal;

    // Construtor que associa um cliente e um quarto a uma reserva.
    Reserva(const Cliente& cliente, const Quarto& quarto)
        : cliente(cliente), quarto(quarto) {
        valorFinal = quarto.calcularPrecoFinal(cliente);
    }

    // Exibe os detalhes da reserva.
    void exibirDetalhes() const {
        std::cout << "Reserva efetuada com sucesso!" << std::endl;
        std::cout << "Cliente: " << cliente.nome << std::endl;
        std::cout << "Quarto N°: " << quarto.numero << std::endl;
        std::cout << "Valor final da diária: R$ " << valorFinal << std::endl;
    }
};

// Classe para gerenciar o hotel, quartos e reservas.
class Hotel {
public:
    static int totalReservas; // Membro estático para contar o número total de reservas.
    static const double PRECO_BASE_DIARIA; // Constante de classe para o preço base da diária.

    std::vector<Quarto> quartos;
    std::vector<Reserva> reservas;

    // Adiciona um novo quarto à lista de quartos do hotel.
    void adicionarQuarto(const Quarto& quarto) {
        quartos.push_back(quarto);
    }

    // Realiza uma reserva para um cliente em um determinado quarto.
    void realizarReserva(const Cliente& cliente, int numeroQuarto) {
        for (const auto& quarto : quartos) {
            if (quarto.numero == numeroQuarto) {
                Reserva novaReserva(cliente, quarto);
                reservas.push_back(novaReserva);
                totalReservas++; // Incrementa o contador de reservas.
                novaReserva.exibirDetalhes();
                return;
            }
        }
        std::cout << "Quarto não encontrado." << std::endl;
    }
};

// Inicialização dos membros estáticos da classe Hotel.
int Hotel::totalReservas = 0;
const double Hotel::PRECO_BASE_DIARIA = 200.00;

// Função principal que demonstra o funcionamento do sistema.
int main() {
    // Cria uma instância da classe Hotel.
    Hotel meuHotel;

    // Adiciona quartos ao hotel, um comum e um de luxo.
    meuHotel.adicionarQuarto(Quarto(101, Hotel::PRECO_BASE_DIARIA));
    meuHotel.adicionarQuarto(Quarto(202, Hotel::PRECO_BASE_DIARIA * Quarto::ADICIONAL_LUXO));

    // Cria instâncias de clientes, um comum e um VIP.
    Cliente clienteComum("Ana Silva", "Comum");
    Cliente clienteVIP("Carlos Andrade", "VIP");

    // Simula a realização de reservas e exibe os detalhes.
    std::cout << "--- Realizando Reserva para Cliente Comum em Quarto de Luxo ---" << std::endl;
    meuHotel.realizarReserva(clienteComum, 202);
    std::cout << "\n--- Realizando Reserva para Cliente VIP em Quarto de Luxo ---" << std::endl;
    meuHotel.realizarReserva(clienteVIP, 202);

    // Exibe o número total de reservas realizadas no hotel.
    std::cout << "\nTotal de reservas no hotel: " << Hotel::totalReservas << std::endl;

    return 0;
}