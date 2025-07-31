#pragma once

#include <iostream>
using namespace std;

struct Item {
    string nome;
    int quantidade;
    float preco;

    Item();
    Item(string nome, int quantidade, float preco);
    Item cadastrarItem();
};