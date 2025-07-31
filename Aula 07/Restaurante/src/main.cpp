#include <iostream>
#include "Restaurante.h"

using namespace std;

/*
Exercício - 1 ponto extra na prova - LP1
Professor: Jerffeson Gomes Dutra
Aluno: Leonardo Nadson Oliveira de Medeiros

Enunciado:
Gere uma aplicação para gerenciar os pedidos de um restaurante.
O restaurante tem um cardápio com vários itens predefinidos com nome e valor.
O restaurante tem 3 mesas com clientes e os clientes podem realizar vários pedidos.
O usuário do sistema recebe o pedido em mãos e atualiza o sistema. 
Ele pode listar as mesas e mostrando se esta aberta e os itens pedidos (com o total vendido até o momento).
Ele pode lançar um pedido para a mesa (Passando o ID do prato solicitado).
Quando os clientes vão embora, deve ser possível puxar os itens pedidos e encerrar a conta da mesa, não sendo possível reabrir a mesa.
Apenas quando as 3 mesas estiverem fechadas, o usuário do sistema pode puxar o resultado das vendas, informando quantos itens do menu foram vendidos, o preço unitário e o valor total e ao final o total vendido.
Dividir as classes em arquivos .h e .cpp
Utilizar o makefile e estrutura padrão do projeto como mostrado em aulas anteriores.
Enviar os arquivos zipados

*/

int main() {
    Restaurante restaurante(3); 
    
    int opcao;
    int numMesa;
    int idItem;

    do {
        cout << "\n===== Sistema de Gestao de Restaurante Junino =====\n";
        cout << "1 - Listar Mesas\n";
        cout << "2 - Adicionar Pedido a Mesa\n";
        cout << "3 - Fechar Conta da Mesa\n";
        cout << "4 - Gerar Relatorio Final de Vendas\n";
        cout << "5 - Ver Cardapio de Itens Juninos\n";
        cout << "0 - Encerrar o sistema\n";
        cout << "Escolha uma opcao: ";
        
        cin >> opcao;

        switch (opcao) {
            case 1:
                restaurante.listarMesas();
                break;
            
            case 2:
                cout << "Digite o numero da mesa: ";
                cin >> numMesa;
                cout << "Digite o ID do item do cardapio: ";
                cin >> idItem;
                restaurante.adicionarPedidoMesa(numMesa, idItem);
                break;
            
            case 3:
                cout << "Digite o numero da mesa para fechar a conta: ";
                cin >> numMesa;
                restaurante.fecharMesa(numMesa);
                break;
            
            case 4:
                restaurante.gerarRelatorioVendas();
                break;
            
            case 5:
                restaurante.getCardapio().imprimirCardapio();
                break;
            
            case 0:
                if (!restaurante.todasMesasFechadas() ) { // Verifica se todas as mesas estao fechadas antes de encerrar o sistema
                    cout << "Tem certeza que deseja sair sem fechar todas as mesas abertas?\n";
                    cout << "0 - Encerrar\n";
                    cout << "1 - Voltar\n";
                    cout << "Escolha uma opção: ";
                    cin >> opcao;
                    if (opcao == 1) {
                        break;
                    }
                }
                cout << "Saindo do sistema...\n";
                break;
            
            default:
                cout << "Opcao inválida. Tente novamente.\n";
                break;
        }

    } while (opcao != 0);

    return 0;
}