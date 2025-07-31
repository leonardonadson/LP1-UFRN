#pragma once

#include "Item.h"
#include <vector>

using namespace std;

class Mesa {
private:
    int numero;
    bool aberta;
    vector<Item> pedidos;

public:
    Mesa(int numero);

    void adicionarPedido(Item item); 
    double calcularTotal();
    void imprimirConta();
    vector<Item> fecharConta();

    bool isAberta();
    int getNumero();
    vector<Item> getPedidos();
};