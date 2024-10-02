#include <iostream>
#include <vector>
#include <stack>

int main() {
    /*
        0 = vazio
        1 = pintado
        2 = ocupado
    */

    int n, m, x, y, k; //n linhas, m colunas, (x,y) coordenadas iniciais, k linhas a seguir
    std::cin >> n >> m >> x >> y >> k;

    std::vector<std::vector<int>> grid(n + 1, std::vector<int>(m+1, 0));
    for (int i = 0; i < k; i++) {
        int a, b;
        std::cin >> a >> b;
        grid[a][b] = 1;  // 1 indica que o quadrado está cheio
    }

    std::stack<std::pair<int, int>> stack;
    stack.push({x, y});
    int result = 0;

    int movements[9][2] = {{-1, -1}, {0, -1}, {+1, -1}, 
                           {-1, 0},  {0, 0},  {+1, 0}, 
                           {-1, +1}, {0, +1}, {+1, +1}};
    
    while (!stack.empty()) {
        int tx, ty;
        tx = stack.top().first;
        ty = stack.top().second;
        stack.pop();

        if (grid[tx][ty] == 0) {
            grid[tx][ty] = 1;
            result++;

            for (auto & x : movements) {
                int dx = tx + x[0], dy = ty + x[1];
                if (dx <= n && dx >= 1 && dy <= m && dy >= 1 && grid[dx][dy] == 0) {
                    stack.push({dx, dy});
                }
            }
        }
    }

    std::cout << result;
}