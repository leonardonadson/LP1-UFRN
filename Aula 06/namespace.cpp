#include <iostream>
#include "matematica.h"

using namespace std;
using namespace matematica;

/*
namespace matematica{
    int soma(int a, int b){
        return a + b;
    }
}
*/

/*
int soma(int a, int b){
    return a * b;
}
*/

int main(){ 
    //cout << "Hello World" << endl;
    cout << soma(2,3) << endl;

    Calculadora c;
    c.soma(4,5);
    
    return 0;
}

/*
int main(){ 
    std::cout << "Hello World" << endl;
    return 0;
}
*/