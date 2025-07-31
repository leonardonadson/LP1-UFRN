#include "funcionario.h"
#include <stdexcept> 

void cadastrarFuncionario::validar(const empresa::Funcionario &funcionario) {
    if (funcionario.idade < 18) {
        // Lança uma exceção do tipo invalid_argument se o funcionário for menor de idade.
        // A mensagem da exceção será capturada pelo bloco catch no main.
        throw std::invalid_argument("Erro: Apenas funcionarios maiores de 18 anos podem ser cadastrados.");
    }
    // Se a idade for válida, a função simplesmente termina sem fazer nada.
}