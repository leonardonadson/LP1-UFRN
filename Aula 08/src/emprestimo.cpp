#include "../include/emprestimo.h"
#include <iostream>

using namespace std;

Emprestimo::Emprestimo(int cId, string lIsbn, string dataEmp)
    : clienteId(cId), livroIsbn(lIsbn), dataEmprestimo(dataEmp), dataDevolucao("Pendente") {}

void Emprestimo::finalizar(string dataDev) {
    dataDevolucao = dataDev;
}

void Emprestimo::exibirDetalhes() const {
    cout << "--- Detalhes do Emprestimo ---" << endl;
    cout << "ID do Cliente: " << clienteId << endl;
    cout << "ISBN do Livro: " << livroIsbn << endl;
    cout << "Data do Emprestimo: " << dataEmprestimo << endl;
    cout << "Data da Devolucao: " << dataDevolucao << endl;
    cout << "-----------------------------" << endl;
}