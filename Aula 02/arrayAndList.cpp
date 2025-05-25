#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> numeros = {1, 2, 3, 4};
    
    int numeros2[] = {1, 2, 3, 4};

    numeros.push_back(6); //Add no fim

    for (int n : numeros) {
        cout << n << endl;
    }

    numeros.pop_back(); //Remove no fim

    
    return 0;
}