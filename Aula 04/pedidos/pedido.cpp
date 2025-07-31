#include "pedido.h"

using namespace std;

Pedido::Pedido(int idPedido, vector <Item> itens, int quantidadeItens, float valorTotal){
    this->idPedido = idPedido;
    this->itens = itens;
    this->quantidadeItens = quantidadeItens;
    this->valorTotal = valorTotal;
}
