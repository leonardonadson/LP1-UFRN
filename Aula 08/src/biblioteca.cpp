#include "../include/biblioteca.h"
#include <iostream>
#include <string>

using namespace std;

// A função getDataAtual() foi removida.

int Biblioteca::encontrarIndiceLivro(string isbn) {
    for (size_t i = 0; i < catalogo.size(); ++i) {
        if (catalogo[i].getIsbn() == isbn) {
            return i;
        }
    }
    return -1;
}

int Biblioteca::encontrarIndiceCliente(int id) {
    for (size_t i = 0; i < clientes.size(); ++i) {
        if (clientes[i].getId() == id) {
            return i;
        }
    }
    return -1;
}

void Biblioteca::adicionarLivro(Livro livro) {
    catalogo.push_back(livro);
}

void Biblioteca::adicionarCliente(Cliente cliente) {
    clientes.push_back(cliente);
}

// A data agora é recebida como um parâmetro
void Biblioteca::realizarEmprestimo(int clienteId, string livroIsbn, string dataAtual) {
    cout << "\n>>> Tentando emprestar livro ISBN '" << livroIsbn << "' para cliente ID " << clienteId << "..." << endl;

    int indiceCliente = encontrarIndiceCliente(clienteId);
    int indiceLivro = encontrarIndiceLivro(livroIsbn);

    if (indiceCliente == -1) {
        cout << "[ERRO] Cliente com ID " << clienteId << " nao encontrado." << endl;
        return;
    }
    if (indiceLivro == -1) {
        cout << "[ERRO] Livro com ISBN '" << livroIsbn << "' nao encontrado." << endl;
        return;
    }

    if (!catalogo[indiceLivro].estaDisponivel()) {
        cout << "[ERRO] O livro '" << catalogo[indiceLivro].getTitulo() << "' ja esta emprestado." << endl;
        return;
    }
    
    if (clientes[indiceCliente].getQuantidadeLivrosEmprestados() >= 3) {
        cout << "[ERRO] O cliente " << clientes[indiceCliente].getNome() << " ja atingiu o limite de 3 livros." << endl;
        return;
    }
    
    catalogo[indiceLivro].emprestar();
    clientes[indiceCliente].pegarLivroEmprestado(livroIsbn);
    // A data é usada aqui
    emprestimosAtivos.push_back(Emprestimo(clienteId, livroIsbn, dataAtual));
    
    cout << "[SUCESSO] Livro '" << catalogo[indiceLivro].getTitulo() << "' emprestado para " << clientes[indiceCliente].getNome() << "." << endl;
}

void Biblioteca::realizarDevolucao(int clienteId, string livroIsbn) {
    cout << "\n>>> Cliente ID " << clienteId << " esta devolvendo o livro ISBN '" << livroIsbn << "'..." << endl;
    
    int indiceCliente = encontrarIndiceCliente(clienteId);
    int indiceLivro = encontrarIndiceLivro(livroIsbn);
    
    if (indiceCliente == -1 || indiceLivro == -1) {
        cout << "[ERRO] Cliente ou Livro nao encontrado para devolucao." << endl;
        return;
    }
    
    catalogo[indiceLivro].devolver();
    clientes[indiceCliente].devolverLivro(livroIsbn);
    cout << "[SUCESSO] Livro devolvido." << endl;
}


void Biblioteca::mostrarLivrosCliente(int clienteId) {
    int indiceCliente = encontrarIndiceCliente(clienteId);
    if (indiceCliente == -1) return;

    Cliente cliente = clientes[indiceCliente];
    cout << "\nLivros atualmente com " << cliente.getNome() << ":" << endl;
    
    vector<string> isbns = cliente.getLivrosEmprestadosIsbn();

    if (isbns.empty()) {
        cout << "  Nenhum." << endl;
    } else {
        for (size_t i = 0; i < isbns.size(); ++i) {
            int indiceLivro = encontrarIndiceLivro(isbns[i]);
            if (indiceLivro != -1) {
                Livro livro = catalogo[indiceLivro];
                cout << "  - " << livro.getTitulo() << " (" << livro.getAutor() << ")" << endl;
            }
        }
    }
}

// IMPLEMENTAÇÃO DA NOVA FUNÇÃO
void Biblioteca::mostrarCatalogoCompleto() const {
    cout << "\n--- Catalogo Completo da Biblioteca ---" << endl;
    if (catalogo.empty()) {
        cout << "O catalogo esta vazio." << endl;
    } else {
        for (size_t i = 0; i < catalogo.size(); ++i) {
            Livro livro = catalogo[i];
            cout << "Titulo: " << livro.getTitulo() << endl;
            cout << "  ISBN: " << livro.getIsbn() 
                 << " | Estado: " << (livro.estaDisponivel() ? "Disponivel" : "Emprestado") << endl;
        }
    }
    cout << "------------------------------------" << endl;
}