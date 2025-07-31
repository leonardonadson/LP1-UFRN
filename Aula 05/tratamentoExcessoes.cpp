#include <iostream>

#include <vector>

using namespace std;

int main() {
    vector<int> numeros = {1,2,3};

    try {
        cout << "Numero: " << numeros.at(5) << endl;
    } catch (const out_of_range& e) {
        cout << "Execeção capturada: " << e.what() << endl;
    }

    return 0;
}