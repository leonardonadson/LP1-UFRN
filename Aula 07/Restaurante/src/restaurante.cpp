#include "Restaurante.h"
#include <iostream>

Restaurante::Restaurante(int numeroDeMesas) { // Construtor de Restaurante que instancia a quantidade de mesas
    for (int i = 1; i <= numeroDeMesas; ++i) {
        mesas.push_back(Mesa(i));
    }
}

void Restaurante::listarMesas() { // Listagem das mesas
    cout << "\n--- Status das Mesas ---\n";
    for (Mesa& mesa : mesas) { // Acessa o endereço do objeto de cada mesa e lista seus dados
        cout << "Mesa " << mesa.getNumero() << ": " << (mesa.isAberta() ? "Aberta" : "Fechada"); //IF ternário para verificar se a mesa esta aberta
        if (mesa.isAberta()) {
            cout << " | Total parcial: R$ " << mesa.calcularTotal() << endl; // Calcula o total parcial da mesa
            
            vector<Item> pedidos = mesa.getPedidos(); // Pega a lista de pedidos da mesa
            if (!pedidos.empty()) {
                for (Item pedido : pedidos) { 
                    cout << "  - " << pedido.getNome() << endl; 
                }
            } else {
                 cout << "  - (Sem pedidos)" << endl;
            }
        } else {
            cout << endl;
        }
    }
     cout << "--------------------------\n";
}

void Restaurante::adicionarPedidoMesa(int numeroMesa, int idItem) { // Adiciona um pedido a uma mesa
    try {
        if (numeroMesa < 1 || numeroMesa > mesas.size()) { // Verifica se o número da mesa é valido
            throw out_of_range("Número da mesa inválido.");
        }

        // Se o número é válido, pegamos a referência da mesa.
        Mesa& mesa = mesas[numeroMesa - 1];

        if (!mesa.isAberta()) { // Verifica se a mesa esta aberta
            throw runtime_error("A mesa " + to_string(numeroMesa) + " já está fechada.");
        }

        Item item = cardapio.getItem(idItem);

        mesa.adicionarPedido(item);
        cout << "Pedido '" << item.getNome() << "' adicionado a mesa " << numeroMesa << ".\n"; // Imprime o pedido adicionado

    } catch (const out_of_range& e) {
        cout << "Erro de validação: " << e.what() << endl;

    } catch (const runtime_error& e) {
        cout << "Erro na operação: " << e.what() << endl;
    }
    
    
    if (numeroMesa < 1 || numeroMesa > mesas.size()) { // Verifica se o numero da mesa é valido
        cout << "Erro: Mesa inválida!\n";
        return;
    }
}

void Restaurante::fecharMesa(int numeroMesa) {
    try {
        if (numeroMesa < 1 || numeroMesa > mesas.size()) { // Verifica se o número da mesa é valido
            throw out_of_range("Numero da mesa invalido.");
        }
        Mesa& mesa = mesas[numeroMesa - 1];

        if (!mesa.isAberta()) { // Verifica se a mesa está fechada
            throw runtime_error("A mesa " + to_string(numeroMesa) + " já foi fechada.");
        }

        mesa.imprimirConta(); // Imprime a conta da mesa
        
        vector<Item> pedidosFechados = mesa.fecharConta(); // Cria um vetor com a lista de pedidos da mesa para o relatório final.
        
        // Adiciona os pedidos da mesa fechada ao vetor de vendas totais do restaurante.
        vendasFechadas.insert(vendasFechadas.end(), pedidosFechados.begin(), pedidosFechados.end()); // Insere os pedidos do vetor pedidosFechados no vetor no do vetor vendasFechadas

    } catch (const out_of_range& e) {
        cout << "Erro de validação: " << e.what() << endl;

    } catch (const runtime_error& e) {
        cout << "Erro na operação: " << e.what() << endl;
    }
}

bool Restaurante::todasMesasFechadas() {
    for (Mesa& mesa : mesas) { // Acessa o endereço do objeto de cada mesa e verifica se todas elas estão fechadas
        if (mesa.isAberta()) {
            return false;
        }
    }
    return true;
}

void Restaurante::gerarRelatorioVendas() {
    try
    {
        if (!todasMesasFechadas()) {
            throw runtime_error("Não é possivel gerar o relatório. Pelo menos uma mesa ainda está aberta.");
            return;
        }

        cout << "\n=========================================\n";
        cout << "       RELATÓRIO FINAL DE VENDAS\n";
        cout << "=========================================\n";

        if (vendasFechadas.empty()) { // Verifica se houve vendas
            cout << "Nenhuma venda registrada.\n";
            cout << "Total Geral Vendido: R$ 0.0\n";
            cout << "=========================================\n";
            return;
        }

        double totalGeral = 0.0;
        vector<Item> menuItens = cardapio.getItens();

        for (Item menuItem : menuItens) {
            int quantidadeVendida = 0;
            for (Item itemVendido : vendasFechadas) { // Verifica quantas vezes o item foi vendido
                if (itemVendido.getId() == menuItem.getId()) {
                    quantidadeVendida++;
                }
            }

            // Se o item foi vendido pelo menos uma vez, mostra no relatório
            if (quantidadeVendida > 0) {
                double precoUnit = menuItem.getValor();
                double totalItem = quantidadeVendida * precoUnit;
                cout << "Item: " << menuItem.getNome() << endl;
                cout << "  Qtd: " << quantidadeVendida << " | Preco Unit.: R$ " << precoUnit 
                    << " | Total: R$ " << totalItem << endl;
                totalGeral += totalItem;
            }
        }

        cout << "-----------------------------------------\n";
        cout << "TOTAL GERAL VENDIDO: R$ " << totalGeral << endl;
        cout << "=========================================\n";

    }
    catch (const runtime_error& e) {
        cout << "Erro na operação: " << e.what() << endl;
    }
    

}

Cardapio Restaurante::getCardapio() {
    return cardapio;
}