#include <iostream>
#include <vector>

int main() {
	int k, n, total = 0;
	std::cin >> k >> n;
    char alfabeto[k];
    char mensagem[n];

	for (int i = 0; i < k; i++) {
		char aux;
		std::cin >> aux;
        alfabeto[i] = aux;
	}

    for (int i = 0; i < n; i++) {
        char aux;
        std::cin >> aux;
        mensagem[i] = aux;
    }

    for (int i = 0; i < n; i++) {
        char aux = mensagem[i];
        for (int j = 0; j < k; j++) {
            if (aux == alfabeto[j]) {
                total++;
            }
        }
    }

    if (total == n) {
        std::cout << 'S';
    } else {
        std::cout << 'N';
    }
}