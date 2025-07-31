#pragma once

#include "Mesa.h"
#include "Cardapio.h"
#include <vector>

using namespace std;

class Restaurante {
private:
    Cardapio cardapio;
    vector<Mesa> mesas;
    vector<Item> vendasFechadas;
public:
    Restaurante(int numeroDeMesas);
    void adicionarPedidoMesa(int numeroMesa, int idItem);
    void fecharMesa(int numeroMesa);
    bool todasMesasFechadas();
    void listarMesas();
    void gerarRelatorioVendas();
    
    Cardapio getCardapio();
};