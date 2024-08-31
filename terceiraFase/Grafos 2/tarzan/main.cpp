#include <iostream>
#include <vector>
#include <stack>
#include <cmath>

#define MAXN 1000
int visited[MAXN];
std::vector<std::pair<int, int>> grid;
std::vector<int> adj[MAXN];

void dfs(int x) {
    for (int i = 0; i < adj[x].size(); i++) {
        int v = adj[x][i];

        if (visited[v] == -1) {
            visited[v] = visited[x];
            dfs(v);
        }
    }
}

int main() {
    int n, d;
    std::cin >> n >> d;

    for(int i = 0; i < n; i++) {
        int x, y;
        std::cin >> x >> y;
        visited[i] = -1;
        grid.push_back({x, y});
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
                int bx, by, ex, ey;
                bx = grid[i].first;
                by = grid[i].second;
                ex = grid[j].first;
                ey = grid[j].second;
                
                int dx, dy, dist;
                dx = bx - ex;
                dy = by - ey;
                dist = (dx*dx) + (dy*dy);

                if (dist <= d*d) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
        }
    }

    int totalComps = 0;
    for (int i = 0; i < n; i++) {
        if (visited[i] == -1) {
            totalComps++;
            visited[i] = totalComps;
            dfs(i);
        }
    }

    if (totalComps == 1) {
        std::cout << 'S';
    } else {
        std::cout << 'N';
    }
    return 0;
}