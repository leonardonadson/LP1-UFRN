#include "../include/biblioteca.h"
#include <iostream>

using namespace std;

int main() {
    Biblioteca biblioteca;
    string dataSimulacao = "2025-06-24"; 

    biblioteca.adicionarLivro(Livro("O Senhor dos Aneis", "J.R.R. Tolkien", "978-0618640157"));
    biblioteca.adicionarLivro(Livro("Fundacao", "Isaac Asimov", "978-0553803716"));
    biblioteca.adicionarLivro(Livro("Duna", "Frank Herbert", "978-0441013593"));
    biblioteca.adicionarLivro(Livro("1984", "George Orwell", "978-0451524935"));

    biblioteca.adicionarCliente(Cliente("Ana Silva", 101));
    biblioteca.adicionarCliente(Cliente("Bruno Costa", 102));

    cout << "====== INICIO DA SIMULACAO DE BIBLIOTECA ======" << endl;

    // Mostrando a lista de livros adicionados
    biblioteca.mostrarCatalogoCompleto();
    
    // Empréstimos agora passam a data como argumento
    biblioteca.realizarEmprestimo(101, "978-0618640157", dataSimulacao);
    biblioteca.realizarEmprestimo(101, "978-0553803716", dataSimulacao);
    biblioteca.realizarEmprestimo(102, "978-0441013593", dataSimulacao);

    biblioteca.realizarEmprestimo(102, "978-0618640157", dataSimulacao);
    biblioteca.realizarEmprestimo(101, "978-0451524935", dataSimulacao);

    // Exibindo estado atual dos clientes
    biblioteca.mostrarLivrosCliente(101);
    biblioteca.mostrarLivrosCliente(102);
    
    // Mostrando o catálogo para ver o estado dos livros
    biblioteca.mostrarCatalogoCompleto();

    // Simulação de devolução
    biblioteca.realizarDevolucao(101, "978-0553803716");
    
    // Novo empréstimo
    biblioteca.realizarEmprestimo(101, "978-0451524935", dataSimulacao);

    cout << "\n------ ESTADO FINAL ------" << endl;
    biblioteca.mostrarLivrosCliente(101);
    biblioteca.mostrarLivrosCliente(102);
    biblioteca.mostrarCatalogoCompleto();

    cout << "\n====== FIM DA SIMULACAO ======" << endl;

    return 0;
}