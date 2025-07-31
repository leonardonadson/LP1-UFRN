#include <iostream>
#include <vector>

using namespace std;



int main() {
    vector<int> numeros;
    int maior = 0, menor;
    float soma;

    cout << "Povoando um vetor" << endl;
    cout << "Digite -1 para parar" << endl;
    
    int valor;
    while(true){
        try{
        cout << "Digite um numero: ";
        cin >> valor;

        if (valor < 0){
            if (valor == -1){
                cout << "Encerrando o programa" << endl;
                cout << "Tamanho do vetor: " << numeros.size() << endl;
                for (int i = 0; i < numeros.size(); i++){
                    if (numeros.at(i) > maior){
                        maior = numeros.at(i);
                    }
                    if (numeros.at(i) < menor){
                        menor = numeros.at(i);
                    }
                    soma = soma + numeros[i];
                }
                cout << "Media do vetor: " <<  (soma / numeros.size()) << endl;
                cout << "Maior do vetor: " << maior << endl;
                cout << "Menor do vetor: " <<  menor << endl;

                break;
            }
            else{
                throw invalid_argument("Numero negativo");
            }
        }
        else if (valor > 10000){
            throw overflow_error("Numero muito grande");
        }
        
        numeros.push_back(valor);
        }
        catch(const exception& e){
            cout << "Excecao capturada: " << e.what() << endl;
        }
        
    }


    return 0;
}