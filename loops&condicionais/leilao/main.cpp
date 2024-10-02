#include <iostream>
#include <vector>
#include <string>

int main() {
    int n, maior = 0, iMaior = 0;
    std::cin >> n;

    std::vector<std::string> nomes;
    std::vector<int> lances;

    for (int i = 0; i < n; i++) {
        int current;
        std::string nameCurrent;

        std::cin >> nameCurrent >> current;

        nomes.push_back(nameCurrent);
        lances.push_back(current);
    }

    for (int i = 0; i < n; i++) {
        int lance = lances[i];
        std::string nome = nomes[i];

        if (lance > maior) {
            maior = lance;
            iMaior = i;
        }
        else if (lance == maior) {
            if (i < iMaior) {
                maior = lance;
            }
        }
    }

    std::cout << nomes[iMaior] << "\n" << maior;
}