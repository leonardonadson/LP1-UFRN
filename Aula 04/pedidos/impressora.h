#pragma once

#include <iostream>
#include "pedido.h"
#include "item.h"

using namespace std;

struct Impressora {

    void imprimirPedido(Pedido pedido);

    void imprimirItem(Item item);
};