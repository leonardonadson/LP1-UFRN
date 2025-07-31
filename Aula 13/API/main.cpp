#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Classes básicas Pessoa e Produto
struct Pessoa {
    int id;
    string nome;
};

struct Produto {
    int id;
    string descricao;
};

// Classe abstrata template EndPoint<T>
template <typename T>
class EndPoint {
public:
    virtual ~EndPoint() = default;

    virtual void criar(const T& item) = 0;
    virtual vector<T> listar() const = 0;
    virtual void editar(int id, const T& item) = 0;
    virtual void deletar(int id) = 0;
};

// Implementação concreta para Pessoa
class PessoaEndPoint : public EndPoint<Pessoa> {
private:
    vector<Pessoa> pessoas;
public:
    void criar(const Pessoa& p) override {
        pessoas.push_back(p);
        cout << "Pessoa criada: " << p.nome << "\n";
    }

    vector<Pessoa> listar() const override {
        return pessoas;
    }

    void editar(int id, const Pessoa& p) override {
        for (auto& pessoa : pessoas) {
            if (pessoa.id == id) {
                pessoa.nome = p.nome;
                cout << "Pessoa editada: " << pessoa.nome << "\n";
                return;
            }
        }
        cout << "Pessoa com ID " << id << " não encontrada.\n";
    }

    void deletar(int id) override {
        pessoas.erase(
            remove_if(pessoas.begin(), pessoas.end(),
                [id](const Pessoa& p) { return p.id == id; }),
            pessoas.end());
        cout << "Pessoa deletada: ID " << id << "\n";
    }
};

// Implementação concreta para Produto
class ProdutoEndPoint : public EndPoint<Produto> {
private:
    vector<Produto> produtos;
public:
    void criar(const Produto& p) override {
        produtos.push_back(p);
        cout << "Produto criado: " << p.descricao << "\n";
    }

    vector<Produto> listar() const override {
        return produtos;
    }

    void editar(int id, const Produto& p) override {
        for (auto& produto : produtos) {
            if (produto.id == id) {
                produto.descricao = p.descricao;
                cout << "Produto editado: " << produto.descricao << "\n";
                return;
            }
        }
        cout << "Produto com ID " << id << " não encontrado.\n";
    }

    void deletar(int id) override {
        produtos.erase(
            remove_if(produtos.begin(), produtos.end(),
                [id](const Produto& p) { return p.id == id; }),
            produtos.end());
        cout << "Produto deletado: ID " << id << "\n";
    }
};

int main() {
    PessoaEndPoint pessoasApi;
    ProdutoEndPoint produtosApi;

    Pessoa p1{1, "João"};
    Pessoa p2{2, "Maria"};

    pessoasApi.criar(p1);
    pessoasApi.criar(p2);

    Produto pr1{1, "Teclado"};
    Produto pr2{2, "Mouse"};

    produtosApi.criar(pr1);
    produtosApi.criar(pr2);

    // Listar pessoas
    cout << "Pessoas cadastradas:\n";
    for (const auto& p : pessoasApi.listar()) {
        cout << "- " << p.id << ": " << p.nome << "\n";
    }

    // Editar pessoa
    pessoasApi.editar(1, Pessoa{1, "João Silva"});

    // Deletar produto
    produtosApi.deletar(2);

    return 0;
}
