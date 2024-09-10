#include <iostream>
#include <vector>
#include <algorithm>

int n, m;
std::vector<std::vector<std::pair<int, int>>> graph;
std::vector<std::vector<int>> dp;

int dfs (int v, int mask) {
    if (dp[v][mask] != -1) return dp[v][mask];
    if (v == n - 1) return 0;
    int maxLenght = -1;
    for (auto & a : graph[v]) {
        int vert = a.first, leng = a.second;
        if (!(mask & (1 << vert))) {
            maxLenght = std::max(maxLenght, leng + dfs(vert, mask | (1 << vert)));
        }
    }
    return dp[v][mask] = maxLenght;
}

int main() {
    std::cin >> n >> m;
    graph.resize(n);
    dp.resize(n, std::vector<int>(1 << n, -1));

    for (int i = 0; i < m; i++) {
        int s, d, l;
        std::cin >> s >> d >> l;
        graph[s].emplace_back(d, l);
    }
    int r = dfs(0, 1);
    
    std::cout << r;
}