#include <iostream>
#include <vector>

int main() {
    int n, k;
    std::cin >> n >> k;
    int notas[n];

    for (int i = 0; i < n; i++) {
        int a;
        std::cin >> a;
        notas[i] = a;
	}

    for (int i = 0; i < n - 1; i++) {
        if (notas[i] > notas[i + 1]) {
            int aux = notas[i + 1];
            notas[i + 1] = notas[i];
            notas[i] = aux;
            i = -1;
        }
    }

    std::cout << notas[n - k] << std::endl;
}