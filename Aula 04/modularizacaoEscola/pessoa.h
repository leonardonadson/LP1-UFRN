#pragma once

#include <iostream>
using namespace std;

struct Aluno
{
    string nome;
    float notas[2];
    float media;

    float Media(float n1, float n2);

    void saudacao(string nome = "Usuario", string saud = "Olá");

};