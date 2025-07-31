#include <iostream>
#include <vector>    
#include <string>
#include <stdexcept> 

#include "funcionario.h" 

// Facilita o uso dos namespaces
using namespace std;
using namespace empresa;
using namespace cadastrarFuncionario;

// Função auxiliar para exibir os funcionários
void exibirTodosFuncionarios(const vector<Funcionario>& lista) {
    cout << "\n--- Lista de Funcionarios Cadastrados ---" << endl;
    if (lista.empty()) {
        cout << "Nenhum funcionario cadastrado." << endl;
    } else {
        for (const auto& f : lista) {
            cout << "Nome: " << f.nome << ", Idade: " << f.idade << ", Salario: R$ " << f.salario << endl;
        }
    }
    cout << "-----------------------------------------" << endl;
}

int main() {
    // Vetor para armazenar todos os funcionários cadastrados com sucesso
    vector<Funcionario> todosOsFuncionarios;
    char continuar = 's';

    cout << "Sistema de Cadastro de Funcionarios" << endl;

    // Loop para continuar cadastrando novos funcionários
    while (continuar == 's' || continuar == 'S') {
        // Cria uma instância temporária de Funcionario para preencher
        Funcionario novoFuncionario;

        cout << "\nDigite o nome do funcionario: ";
        cin >> novoFuncionario.nome;

        cout << "Digite a idade do funcionario: ";
        cin >> novoFuncionario.idade;

        cout << "Digite o salario do funcionario: ";
        cin >> novoFuncionario.salario;

        try {
            // 1. Tenta validar o funcionário
            validar(novoFuncionario);

            // 2. Se a validação não lançar uma exceção, o funcionário é válido.
            //    Adiciona ele ao vetor.
            todosOsFuncionarios.push_back(novoFuncionario);
            cout << "Funcionario cadastrado com sucesso!" << endl;

        } catch (const invalid_argument& e) {
            // 3. Se uma exceção foi lançada, o bloco catch a captura.
            //    O funcionário NÃO é adicionado à lista.
            cerr << e.what() << endl; // exibe a mensagem de erro
        }

        cout << "\nDeseja cadastrar outro funcionario? (s/n): ";
        cin >> continuar;
    }

    // Após o loop, exibe todos os funcionários que foram cadastrados
    exibirTodosFuncionarios(todosOsFuncionarios);

    return 0;
}