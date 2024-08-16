#include <iostream>

int main() {
    int n, m;
    std::cin >> n >> m;

    int inicial[n][m];
    int final[n][m];
    int visitadas[(n*m)];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int aux;
            std::cin >> aux;
            inicial[i][j] = aux;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            //player = inicial[i][j]
            
            if (inicial[i][j] >= inicial[i+1][j]) {
                inicial[i+1][j] += inicial[i][j]; //aqui paremo, mta mao
            }
        }
    }
}