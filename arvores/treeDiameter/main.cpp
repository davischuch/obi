#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int const MAXN = 200100;
int dist1[MAXN], dist2[MAXN];

void bfs1(int p, std::vector<std::vector<int>> g) {
    std::queue<int> queue;
    std::vector<bool> visited(MAXN, false);
    queue.push(p);

    while(!queue.empty()) {
        int v = queue.front();
        queue.pop();
        visited[v] = true;

        for (int i = 0; i < g[v].size(); i++) {
            int aux = g[v][i];
            if (!visited[aux]) {
                queue.push(aux);
                dist1[aux] = dist1[v] + 1;
            }
        }
    }
}

void bfs2(int p, std::vector<std::vector<int>> g) {
    std::queue<int> queue;
    std::vector<bool> visited(MAXN, false);
    queue.push(p);

    while(!queue.empty()) {
        int v = queue.front();
        queue.pop();
        visited[v] = true;

        for (int i = 0; i < g[v].size(); i++) {
            int aux = g[v][i];
            if (!visited[aux]) {
                queue.push(aux);
                dist2[aux] = dist2[v] + 1;
            }
        }
    }
}

int main() {
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> graph(n + 1);

    for (int i = 1; i < n; i++) {
        int a, b;
        std::cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    bfs1(1, graph);
    int max = -1, v = 0;
    for (int i = 1; i <= n; i++) {
        if (dist1[i] > max) {
            max = dist1[i];
            v = i;
        }
    }
    
    bfs2(v, graph);
    int res = -1;
    for (int i = 1; i <= n; i++) {
        res = std::max(res, dist2[i]);
    }
    
    std::cout << res;
}