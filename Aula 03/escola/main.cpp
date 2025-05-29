#include <iostream>

using namespace std;

struct Aluno
{
    string nome;
    float notas[2];
    float media;

    float Media(float n1, float n2){
        return (n1 + n2) / 2;
    }

};

int BuscarAluno(Aluno alunos[], int qtdAlunos, string nome){
    for (int i = 0; i < qtdAlunos; i++){
        if (alunos[i].nome == nome){
            return i;
        }
        else{
            return -1;
        }
    }
};

int MediaGeral(Aluno alunos[], int qtdAlunos){
    int mediaGeral = 0;
    for (int i = 0; i < qtdAlunos; i++){
        mediaGeral += alunos[i].media;
    }
    return mediaGeral / qtdAlunos;
}

int main(){
    int qtdAlunos;

    // Quantidade de alunos na escola
    do{
        cout << "Quantos alunos deseja cadastrar?" << endl;
        cin >> qtdAlunos;
    } while (qtdAlunos > 10);
    
    // Inserindo alunos
    Aluno alunos[qtdAlunos];

    // Cadastrando alunos
    for (int i = 0; i < qtdAlunos; i++)
    {
        cout << "Digite o nome do aluno: " << endl;
        cin >> alunos[i].nome;

        cout << "Digite a primeira nota do aluno: " << endl;
        cin >> alunos[i].notas[0];
        cout << "Digite a segunda nota do aluno: " << endl;
        cin >> alunos[i].notas[1];

        alunos[i].media = alunos[i].Media(alunos[i].notas[0], alunos[i].notas[1]);
    }

    // Listando os alunos cadastrados
    cout << "Dado cadastrado no Sistema: " << endl;
    for (int i = 0; i < qtdAlunos; i++)
    {
        cout << endl << "Dados do aluno:" << endl;
        cout << "Nome: " << alunos[i].nome << endl;
        cout << "Media: " << alunos[i].media << endl;
    }

    // Calculando a media geral
    cout << endl << "Media geral: " << MediaGeral(alunos, qtdAlunos) << endl;

    // Buscas
    cout << endl << "Deseja realizar buscas?" << endl;
    cout << "0 - Nao" << endl;
    cout << "1 - Sim" << endl;
    int opcaoBusca;
    cin >> opcaoBusca;

    if (opcaoBusca == 0){
        cout << "Busca encerrada!" << endl;
        return 0;
    }

    else{
        cout << endl << "Realizando buscas: " << endl;
        string alunoBusca;
        cout << "Digite o nome do aluno que deseja buscar: " << endl;
        cin >> alunoBusca;

        int alunoEncontrado = BuscarAluno(alunos, qtdAlunos, alunoBusca);

        // Verificando se o aluno foi encontrado
        if (alunoEncontrado == -1){
            cout << "Aluno nao encontrado!" << endl;
            return 0;
        }
        else{
            // Exibindo os dados do aluno
            cout << "Dados do aluno encontrado: " << endl;
            cout << "Nome: " << alunos[alunoEncontrado].nome << endl;
            cout << "Media: " << alunos[alunoEncontrado].media << endl;
        }
    }
    return 0;
}