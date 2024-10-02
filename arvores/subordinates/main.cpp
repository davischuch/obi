#include <iostream>
#include <vector>

int const MAXN = 200100;
std::vector<std::vector<int>> graph(MAXN);
std::vector<int> size(MAXN, 0);
std::vector<bool> visited(MAXN, false);

int dfs(int v) {
    visited[v] = true;
    size[v] += graph[v].size();

    for (int i = 0; i < graph[v].size(); i++) {
        if (!visited[graph[v][i]]) {
            size[v] += dfs(graph[v][i]);
        }
    }
    return size[v];
}

int main () {
    int n;
    std::cin >> n;

    for (int i = 2; i <= n; i++) {
        int aux;
        std::cin >> aux;
        graph[aux].push_back(i);
    }
    dfs(1);

    for (int i = 1; i <= n; i++) {
        std::cout << size[i] << " ";
    }
}