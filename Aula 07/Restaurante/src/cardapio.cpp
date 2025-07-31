#include "../include/cardapio.h"
#include <iostream>

Cardapio::Cardapio() { // Construtor de Cardapio instanciando itens. Optei por criar um cardápio junino, aproveitando a epoca
    itens.push_back(Item(1, "Pamonha", 10.00));
    itens.push_back(Item(2, "Canjica", 7.00));
    itens.push_back(Item(3, "Milho Assado", 5.50));
    itens.push_back(Item(4, "Milho Cozido", 5.00));
    itens.push_back(Item(5, "Arroz Doce", 8.50));
    itens.push_back(Item(6, "Agua com Gas", 4.00));
    itens.push_back(Item(7, "Agua sem Gas", 4.00));
    itens.push_back(Item(8, "Suco de Laranja", 8.00));
    itens.push_back(Item(9, "Refrigerante Coca-Cola", 8.00));
    itens.push_back(Item(10, "Refrigerante Guaraná", 8.00));
    itens.push_back(Item(10, "Refrigerante Cajuína", 8.00));
}

Item Cardapio::getItem(int id) { // Busca um item pelo ID
    for (Item item : itens) { 
        if (item.getId() == id) {
            return item;
        }
    }
    throw runtime_error("Item com ID " + to_string(id) + " não encontrado no cardápio.");
}

void Cardapio::imprimirCardapio() { // Imprime o cardapio
    cout << "\n--- Cardapio ---\n";
    cout << "ID\tPrato\t\t\t\tValor (R$)\n";
    cout << "---------------------------------------------------------\n";
    for (Item item : itens) { // Imprime todos os itens do cardapio com seu ID, nome e valor
        cout << item.getId() << "\t" << item.getNome() << "\t\t" << item.getValor() << endl;
    }
    cout << "---------------------------------------------------------\n";
}

vector<Item> Cardapio::getItens() { // Get da lista de itens do cardapio
    return itens;
}