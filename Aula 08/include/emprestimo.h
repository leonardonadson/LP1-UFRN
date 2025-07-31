#pragma once

#include <string>

class Emprestimo {
private:
    int clienteId;
    std::string livroIsbn;
    std::string dataEmprestimo;
    std::string dataDevolucao;

public:
    Emprestimo(int cId, std::string lIsbn, std::string dataEmp);

    void finalizar(std::string dataDev);
    void exibirDetalhes() const;
};