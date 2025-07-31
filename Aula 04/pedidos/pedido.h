#pragma once

#include <iostream>
#include "item.h"
#include <vector>

using namespace std;

struct Pedido
{
    int idPedido = 0;
    vector <Item> itens;
    int quantidadeItens = 0;
    float valorTotal = 0;

    Pedido(int idPedido, vector<Item> itens, int quantidadeItens, float valorTotal);

    
};
