#include "impressora.h"

void Impressora::imprimirPedido(Pedido pedido){
    cout << "Impressão do pedido: " << endl;

    cout << "Numero do pedido: " << pedido.idPedido << endl;

    for (int i = 0; i < pedido.quantidadeItens; i++){
        imprimirItem(pedido.itens[i]);
    }

    cout << "Valor total: " << pedido.valorTotal << endl;

}

void Impressora::imprimirItem(Item item){
    cout << "Item: " << item.nome << endl;
    cout << "Quantidade: " << item.quantidade << endl;
    cout << "Preço: " << item.preco << endl;
}