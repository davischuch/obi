#include <iostream>

int main() {
    int n, q;
    std::cin >> n >> q;
    int lista[n];
    int respostas[q];

    for (int i = 0; i < n; i++) {
        int aux;
        std::cin >> aux;
        lista[i] = aux;
    }
    for (int x = 0; x < q; x++) {
        int a, b;
        int value = 0;
        std::cin >> a >> b;
        for (int i = (a - 1); i < b; i++) {
            for (int j = (a - 1); j < b; j++) {
                if (i != j) {
                    value += (lista[i]*10) + lista[j];
                }
            }
        }
        respostas[x] = value;
    }
    
    for (int i = 0; i < q; i++) {
        std::cout << respostas[i] << std::endl;
    }
}