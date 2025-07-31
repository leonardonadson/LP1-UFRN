#include "../include/cliente.h"
#include <iostream>

using namespace std;

Cliente::Cliente() : nome(""), idUnico(0) {}

Cliente::Cliente(string in_nome, int id) : nome(in_nome), idUnico(id) {}

string Cliente::getNome() const {
    return nome;
}

int Cliente::getId() const {
    return idUnico;
}

int Cliente::getQuantidadeLivrosEmprestados() const {
    return livrosEmprestadosIsbn.size();
}

vector<string> Cliente::getLivrosEmprestadosIsbn() const {
    return livrosEmprestadosIsbn;
}

void Cliente::pegarLivroEmprestado(string isbn) {
    livrosEmprestadosIsbn.push_back(isbn);
    
    // Verifica manualmente se o ISBN já existe no histórico antes de adicionar
    bool encontrado = false;
    for (size_t i = 0; i < historicoDeEmprestimosIsbn.size(); ++i) {
        if (historicoDeEmprestimosIsbn[i] == isbn) {
            encontrado = true;
            break;
        }
    }
    if (!encontrado) {
        historicoDeEmprestimosIsbn.push_back(isbn);
    }
}

void Cliente::devolverLivro(string isbn) {
    for (size_t i = 0; i < livrosEmprestadosIsbn.size(); ++i) {
        if (livrosEmprestadosIsbn[i] == isbn) {
            livrosEmprestadosIsbn.erase(livrosEmprestadosIsbn.begin() + i);
            break; 
        }
    }
}

void Cliente::mostrarHistorico() const {
    cout << "Historico de ISBNs de livros para " << nome << ":" << endl;
    if (historicoDeEmprestimosIsbn.empty()) {
        cout << "  Nenhum livro no historico." << endl;
    } else {
        for (size_t i = 0; i < historicoDeEmprestimosIsbn.size(); ++i) {
            cout << "  - ISBN: " << historicoDeEmprestimosIsbn[i] << endl;
        }
    }
}