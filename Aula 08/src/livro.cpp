#include "../include/livro.h"

using namespace std;

Livro::Livro() : titulo(""), autor(""), isbn(""), disponivel(false) {}

Livro::Livro(string in_titulo, string in_autor, string in_isbn)
    : titulo(in_titulo), autor(in_autor), isbn(in_isbn), disponivel(true) {}

string Livro::getTitulo() const {
    return titulo;
}

string Livro::getAutor() const {
    return autor;
}

string Livro::getIsbn() const {
    return isbn;
}

bool Livro::estaDisponivel() const {
    return disponivel;
}

void Livro::emprestar() {
    if (disponivel) {
        disponivel = false;
    }
}

void Livro::devolver() {
    if (!disponivel) {
        disponivel = true;
    }
}