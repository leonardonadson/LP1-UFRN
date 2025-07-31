#pragma once

#include <string>
#include <iostream>

class Conta;

using namespace std;

struct Transferencia {
    double valor;
    Conta& contaOrigem;
};

class Conta {
private:
    int numero;
    string titular;
    double saldo;

public:
    Conta();
    Conta(int numero, const string& titular, double saldoInicial);

    Conta& operator+=(double valor);
    Transferencia operator-(double valor);
    Conta& operator=(const Transferencia& transferencia);

    friend ostream& operator<<(ostream& os, const Conta& conta);

    double getSaldo() const;
};