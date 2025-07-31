#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include <string>

// Namespace para agrupar a estrutura de dados da empresa
namespace empresa {
    
    struct Funcionario {
        std::string nome;
        int idade;
        float salario;
    };

}

// Namespace para agrupar as funções relacionadas ao cadastro
namespace cadastrarFuncionario {
    
    // Declaração da função que irá validar e lançar a exceção.
    // Recebe o funcionário como uma referência constante, pois só precisa ler os dados.
    void validar(const empresa::Funcionario &funcionario);
}

#endif // FUNCIONARIO_H