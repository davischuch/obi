#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int main() {
    int n, m, result = 0;
    std::cin >> n >> m;

    std::vector<int> carros(n);
    std::vector<int> mecanicos(m);
    std::vector<int> atendimentos(m, 0);
    std::priority_queue<std::pair<int, int>> pq;

    for (int i = 0; i < n; i++) {
        int aux;
        std::cin >> aux;
        carros[i] = aux;
    }
    for (int i = 0; i < m; i++) {
        int aux;
        std::cin >> aux;
        mecanicos[i] = aux;
        pq.push({0, i});
    }

    std::sort(mecanicos.begin(), mecanicos.end());
    std::sort(carros.begin(), carros.end());
    std::reverse(carros.begin(), carros.end());

    for (auto & c : carros) {
        int tempo = (-c*pq.top().first), valor = pq.top().second;
        pq.pop();
        atendimentos[valor]++;
        result += tempo;
        pq.push({-atendimentos[valor]*mecanicos[valor] ,valor});
    }

    std::cout << result;
}