#pragma once

#include <string>
#include <vector>

class Cliente {
private:
    std::string nome;
    int idUnico;
    std::vector<std::string> livrosEmprestadosIsbn; 
    std::vector<std::string> historicoDeEmprestimosIsbn;

public:
    Cliente();
    Cliente(std::string nome, int id);

    std::string getNome() const;
    int getId() const;
    int getQuantidadeLivrosEmprestados() const;
    std::vector<std::string> getLivrosEmprestadosIsbn() const;

    void pegarLivroEmprestado(std::string isbn);
    void devolverLivro(std::string isbn);
    
    void mostrarHistorico() const;
};