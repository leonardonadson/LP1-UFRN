#pragma once

#include <string>

class Livro {
private:
    std::string titulo;
    std::string autor;
    std::string isbn;
    bool disponivel;

public:
    Livro(); 
    Livro(std::string titulo, std::string autor, std::string isbn);

    std::string getTitulo() const;
    std::string getAutor() const;
    std::string getIsbn() const;
    bool estaDisponivel() const;

    void emprestar();
    void devolver();
};