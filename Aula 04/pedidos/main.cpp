#include <iostream>
#include "impressora.h"

using namespace std;

Item cadastrarItem(){
    Item item;
    cout << "Digite o nome do item: " << endl;
    cin >> item.nome;
    cout << "Digite a quantidade do item: " << endl;
    cin >> item.quantidade;
    cout << "Digite o preco do item: " << endl;
    cin >> item.preco;
    return item;
}

void cadastrarPedido(Pedido pedido){
    int quantidadeItens = 0;
    float valorTotal = 0;
    pedido.itens.push_back(item);
    quantidadeItens += item.quantidade;
    valorTotal += item.preco * item.quantidade;
    pedido.quantidadeItens = quantidadeItens;
    pedido.valorTotal = valorTotal;
}

int main(){
    int valor;
    switch (valor)
    {

    }



    return 0;
}
