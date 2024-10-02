#include <iostream>
#include <vector>

int main() {
    int m, n, p, vendas = 0; // m = tipos; n = tamanhos; p = pedidos
    std::cin >> m >> n;

    std::vector<std::vector<int>> tipos;
    std::vector<int> tamanhos;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int current;
            std::cin >> current;
            tamanhos.push_back(current);
        }
        tipos.push_back(tamanhos);
        tamanhos.clear();
    }

    std::cin >> p;

    for (int i = 0; i < p; i++) {
        int I, J; //I = tipo; J = Tamanho
        std::cin >> I >> J;
        I = I - 1;
        J = J - 1;

        std::vector<int> tipoAtual = tipos[I];
        int itemAtual = tipoAtual[J];

        if (itemAtual == 0) {
            continue;
        }
        else {
            tipoAtual[J] = tipoAtual[J] - 1;
            tipos[I] = tipoAtual;
            vendas++;
        }
    }

    std::cout << vendas;
}