#include "../include/item.h"

Item::Item(int id, string nome, double valor) { // Construtor de Item
    this->id = id;
    this->nome = nome;
    this->valor = valor;
}

/*
Abaixo temos os Getters e Setters da classe Item. 
Não vimos ainda oficialmente encapsulamento na disciplina. 
Apesar disso, optei por utilizar por estar mais acostumado com esse padrão no dia-a-dia
*/

void Item::setId(int id) { // Set do ID
    this->id = id;
}

int Item::getId() { // Get do ID
    return id;
}

void Item::setNome(string nome) { // Set do Nome
    this->nome = nome;
}

string Item::getNome() { // Get do Nome
    return nome;
}

void Item::setValor(double valor) { // Set do Valor
    this->valor = valor;
}

double Item::getValor() { // Get do Valor
    return valor;
}