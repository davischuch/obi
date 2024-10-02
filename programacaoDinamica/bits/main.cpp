#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int N, K;
    cin >> N >> K;

    vector<vector<int>> dp(N+1, vector<int>(K, 0));
    
    dp[1][0] = 1; // Sequência que termina com 0
    dp[1][1] = 1; // Sequência que termina com 1
    
    for (int n = 2; n <= N; ++n) {
        dp[n][0] = 0;
        for (int k = 0; k <= K-1; ++k) {
            dp[n][0] = (dp[n][0] + dp[n-1][k]) % MOD;
        }
        
        for (int k = 1; k <= K-1; ++k) {
            dp[n][k] = dp[n-1][k-1];
        }
    }

    int result = 0;
    for (int k = 0; k <= K-1; ++k) {
        result = (result + dp[N][k]) % MOD;
    }

    cout << result << endl;

    return 0;
}