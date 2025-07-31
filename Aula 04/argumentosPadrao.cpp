#include <iostream>

using namespace std;

void saudacao(string nome = "Usuario", string saud = "Olá"){
    cout << saud << ", " << nome << " !" << endl;
}

int main() {
    saudacao(); //Olá, Usuario
    saudacao("João"); //Olá, João
    saudacao("Maria", "Bom dia"); //Bom dia, Maria
    
    return 0;
}