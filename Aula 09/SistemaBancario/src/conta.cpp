#include "conta.h"
#include <stdexcept>

Conta::Conta() : numero(0), titular(""), saldo(0.0) {}

Conta::Conta(int numero, const string& titular, double saldoInicial)
    : numero(numero), titular(titular), saldo(saldoInicial) {
    if (saldoInicial < 0) {
        throw invalid_argument("O saldo inicial não pode ser negativo.");
    }
}

Conta& Conta::operator+=(double valor) {
    if (valor <= 0) {
        throw invalid_argument("O valor do depósito deve ser positivo.");
    }
    this->saldo += valor;
    return *this;
}

Transferencia Conta::operator-(double valor) {
    if (valor <= 0) {
        throw invalid_argument("O valor da transferência deve ser positivo.");
    }
    if (this->saldo < valor) {
        throw runtime_error("Saldo insuficiente para realizar a transferência.");
    }
    return {valor, *this};
}

Conta& Conta::operator=(const Transferencia& transferencia) {
    transferencia.contaOrigem.saldo -= transferencia.valor;
    this->saldo += transferencia.valor;
    return *this;
}

ostream& operator<<(ostream& os, const Conta& conta) {
    os << "------------------------\n"
       << "Numero da Conta: " << conta.numero << "\n"
       << "Titular: " << conta.titular << "\n"
       << "Saldo: R$ " << conta.saldo << "\n"
       << "------------------------";
    return os;
}

double Conta::getSaldo() const {
    return this->saldo;
}