#include <iostream>
#include "matematica.h"

using namespace std;

namespace matematica{
    int soma(int a, int b) { 
        return a + b;
    }

    int subtracao(int a, int b) { 
        return a - b;
    }

    int multiplicacao(int a, int b) { 
        return a * b;
    }

    int divisao(int a, int b) { 
        return a / b;
    }

    void Calculadora::soma(int a, int b) { 
        cout << a + b ;
    }
}

