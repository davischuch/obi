#include <iostream>
#include <vector>

int main() {
    int v, m;
    std::cin >> v >> m;

    std::vector<int> moedas(m);
    std::vector<bool> dp(v + 1, false);

    for (int i = 0; i < m; i++) {
        std::cin >> moedas[i];
    }
    
    dp[0] = true;
    
    for (int i = 0; i < m; i++) {
        for (int j = v; j >= moedas[i]; j--) {
            if (dp[j - moedas[i]]) {
                dp[j] = true;
            }
        }
    }

    if (dp[v]) {
        std::cout << 'S' << std::endl;
    } else {
        std::cout << 'N' << std::endl;
    }

    return 0;
}
