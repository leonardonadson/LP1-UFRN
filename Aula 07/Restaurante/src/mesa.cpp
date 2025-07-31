#include "../include/mesa.h"
#include <iostream>

Mesa::Mesa(int numero) {
    this->numero = numero;
    this->aberta = true; // Valor padrão, a mesa sempre começa aberta
}

void Mesa::adicionarPedido(Item item) {
    pedidos.push_back(item); // Adiciona um pedido a lista de itens da mesa
}

double Mesa::calcularTotal() {
    double total = 0.0;
    for (Item item : pedidos) {  // Pega todos os itens da mesa e soma seu valor
        total += item.getValor();
    }
    return total;
}

void Mesa::imprimirConta() {
    cout << "\n--- Conta da Mesa " << numero << " ---\n";
    if (pedidos.empty()) {
        cout << "Nenhum item consumido.\n";
    } else {
        for (Item item : pedidos) { // Lista todos os itens da mesa, com seu nome e valor
            cout << "- " << item.getNome() << " (R$ " << item.getValor() << ")\n";
        }
    }
    cout << "------------------------\n";
    cout << "Total: R$ " << calcularTotal() << endl; // Calcula o total da mesa e imprime
    cout << "------------------------\n";
}

vector<Item> Mesa::fecharConta() {
    this->aberta = false; // Muda o valor padrão da mesa para fechada
    cout << "Conta da mesa " << numero << " fechada.\n";
    return pedidos;
}

bool Mesa::isAberta() { // Verifica se a mesa está aberta
    return aberta;
}

int Mesa::getNumero() { // Retorna o numero da mesa
    return numero;
}

vector<Item> Mesa::getPedidos() { // Retorna a lista de pedidos da mesa
    return pedidos;
}