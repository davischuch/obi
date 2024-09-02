#include <iostream>
#include <vector>
#include <map>
#include <queue>

#define MAXN 1000
#define INF 1000000000
std::vector<std::pair<int,int>> graph[MAXN];
std::map<int, int> prev;
std::map<int, int> dist;
std::priority_queue<std::pair<int, int>> list;

int main() {
    int n, m; //n vertices (0 inicio, n + 1 final), m arestas 
    std::cin >> n >> m; 

    for (int i = 0; i < m; i++) {
        int s, t, b; //ligacao (s, t), b buracos
        std::cin >> s >> t >> b;
        graph[s].push_back({t, b}); //vetor, peso
        graph[t].push_back({s, b});
    }

    for (int i = 0; i <= n + 1; i++) {
        dist[i] = INF;
        prev[i] = -1;
    }
    dist[0] = 0;
    list.push({dist[0], 0}); //distancia, vertice

    while(!list.empty()) {
        int v = list.top().second;
        list.pop();

        for (auto & w : graph[v]) {
            if (dist[v] + w.second < dist[w.first]) {
                dist[w.first] = dist[v] + w.second;
                prev[w.first] = v;
                list.push({dist[w.first], w.first});
            }
        }
    }

    std::cout << dist[n + 1];
}