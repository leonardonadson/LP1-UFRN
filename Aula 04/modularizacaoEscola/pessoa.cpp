#include "pessoa.h"

float Aluno::Media(float n1, float n2) {
    return (n1 + n2) / 2; 
}

void Aluno::saudacao(string nome, string saud){
    cout << saud << ", " << nome << " !" << endl;
}