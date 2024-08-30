#include <iostream>
#include <vector>

#define MAXN 1000
int componente[MAXN];
std::vector<int> lista[MAXN];

void dfs(int x) {
    for (int i = 0; i < lista[x].size(); i++) {
        int v = lista[x][i];

        if (componente[v] == -1) {
            componente[v] = componente[x];
            dfs(v);
        }
    }
}

int main() {
    int n, m; //n alunos na turma, m linhas na lista
    std::cin >> n >> m;

    for(int i = 0; i < n; i++) componente[i] = -1;

    for (int i = 0; i < m; i++) {
        int a, b;
        std::cin >> a >> b;
        lista[a].push_back(b);
        lista[b].push_back(a);
    }

    int numeroComponentes = 0;
    for (int i = 1; i <= n; i++) {
        if (componente[i] == -1) {
            numeroComponentes++;
            componente[i] = numeroComponentes;
            dfs(i);
        }
    }

    std::cout << numeroComponentes << std::endl;
    return 0;
}