#include <iostream>
#include <vector>
#include <queue>

const int INF = 1e9;
int xMovements[] = {-1, +1, 0, 0};
int yMovements[] = {0, 0, -1, +1};

struct Node {
    int x, y, d;
    bool operator<(const Node& other) const {
        return d > other.d;
    }
};

int main() {
    int n, w;
    std::cin >> n;

    std::vector<std::vector<int>> mina(n, std::vector<int>(n));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> mina[i][j];
        }
    }

    std::vector<std::vector<int>> dist(n, std::vector<int>(n, INF));
    std::priority_queue<Node> list;

    dist[0][0] = mina[0][0];
    list.push({0, 0, dist[0][0]});

    while(!list.empty()) {
        Node v = list.top();
        list.pop();

        int x = v.x, y = v.y, d = v.d;


        for (int i = 0; i < 4; i++) {
            int tx = x + xMovements[i], ty = y + yMovements[i];
            if (tx < n && tx >= 0 && ty < n && ty >= 0) {
                int dv = d + mina[tx][ty];
                if (dv < dist[tx][ty]) {
                    dist[tx][ty] = dv;
                    list.push({tx, ty, dist[tx][ty]});
                }
            }
        }
    }

    std::cout << dist[n - 1][n - 1] << std::endl;
}