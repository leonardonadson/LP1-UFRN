#pragma once

#include "Livro.h"
#include "Cliente.h"
#include "Emprestimo.h"
#include <vector>
#include <string>

class Biblioteca {
private:
    std::vector<Livro> catalogo;
    std::vector<Cliente> clientes;
    std::vector<Emprestimo> emprestimosAtivos;

    int encontrarIndiceLivro(std::string isbn);
    int encontrarIndiceCliente(int id);

public:
    void adicionarLivro(Livro livro);
    void adicionarCliente(Cliente cliente);
    
    void realizarEmprestimo(int clienteId, std::string livroIsbn, std::string dataAtual);
    void realizarDevolucao(int clienteId, std::string livroIsbn);
    
    void mostrarLivrosCliente(int clienteId);
    void mostrarCatalogoCompleto() const; 
};