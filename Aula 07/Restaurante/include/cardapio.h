#pragma once

#include "Item.h"
#include <vector>
#include <string>

using namespace std;

class Cardapio {
private:
    vector<Item> itens;

public:
    Cardapio(); 
    
    Item getItem(int id); 
    void imprimirCardapio();
    
    vector<Item> getItens();
};