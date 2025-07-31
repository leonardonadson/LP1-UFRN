#pragma once

#include <string>

using namespace std;

class Item {
private:
    int id;
    string nome;
    double valor;

public:
    Item(int id, string nome, double valor);

    void setId(int id);
    int getId();
    void setNome(string nome);
    string getNome();
    void setValor(double valor);
    double getValor();
};