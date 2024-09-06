#include <iostream>
#include <vector>
#include <algorithm>

const int INF = 1e9;

int main() {
    int s, c; //s vertices, c arestas
    std::cin >> s >> c;

    std::vector<std::vector<int>> graph(s + 1, std::vector<int>(s + 1, INF));

    for (int i = 0; i < c; i++) {
        int a, b, d;
        std::cin >> a >> b >> d;
        graph[a][b] = d;
        graph[b][a] = d;
    }
    for (int i = 1; i <= s; i++) {
        graph[i][i] = 0;
    }

    for (int k = 1; k <= s; k++) {
        for (int i = 1; i <= s; i++) {
            for (int j = 1; j <= s; j++) {
                if (graph[i][k] < INF && graph[k][j] < INF) {
                    graph[i][j] = std::min(graph[i][j], graph[i][k] + graph[k][j]);
                }
            }
        }
    }

    int minMaxDist = INF;
    for (int i = 1; i <= s; i++) {
        int maxDist = 0;
        for (int j = 1; j <= s; j++) {
            maxDist = std::max(maxDist, graph[i][j]);
        }
        minMaxDist = std::min(minMaxDist, maxDist);
    }
    std::cout << minMaxDist << std::endl;
    return 0;
}