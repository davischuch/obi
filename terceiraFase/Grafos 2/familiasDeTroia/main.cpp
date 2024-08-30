#include <iostream>
#include <vector>

#define MAXN 50000
int componentes[MAXN];
std::vector<int> lista[MAXN];

void dfs(int x) {
    for (int i = 0; i < lista[x].size(); i++) {
        int v = lista[x][i];

        if (componentes[v] == -1) {
            componentes[v] = componentes[x];
            dfs(v);
        }
    }
}

int main() {
    int n, m; //n vertices, m + 1 linhas
    std::cin >> n >> m;

    for (int i = 0; i < n; i++) {
        componentes[i] = -1;
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        std::cin >> a >> b;
        lista[a].push_back(b);
        lista[b].push_back(a);
    }
    
    int numeroComponentes = 0;
    for (int i = 1; i < n; i++) {
        if (componentes[i] == -1) {
            numeroComponentes++;
            componentes[i] = numeroComponentes;
            dfs(i);
        }
    }
    std::cout << numeroComponentes;
}