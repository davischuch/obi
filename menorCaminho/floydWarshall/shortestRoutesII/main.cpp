#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
 
#define MAXN 500
const long long int INF = LLONG_MAX - 1;
 
int main() {
    int n, m, q;
    std::cin >> n >> m >> q;
 
    std::vector<std::vector<long long int>> graph(n+1, std::vector<long long int>(n+1, INF));
    for (int i = 1; i <= n; ++i) {
        graph[i][i] = 0;
    }
    std::queue<std::pair<int, int>> queue;
 
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        std::cin >> a >> b >> c;
        if (c < graph[a][b]) {
            graph[a][b] = c;
            graph[b][a] = c;
        }
    }
    for (int i = 0; i < q; i++) {
        int a, b;
        std::cin >> a >> b;
        queue.push({a, b});
    }
 
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (graph[i][k] < INF && graph[k][j] < INF) {
                    if (graph[i][j] > graph[i][k] + graph[k][j]) {
                        graph[i][j] = graph[i][k] + graph[k][j];
                    }
                }
            }   
        }
    }
 
    while (!queue.empty()) {
        int a = queue.front().first, b = queue.front().second;
        queue.pop();
        if (graph[a][b] == INF) {
            std::cout << -1 << std::endl;
        } else {
            std::cout << graph[a][b] << std::endl;
        }
    }
    return 0;
}
