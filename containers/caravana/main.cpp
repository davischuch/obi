#include <iostream>
#include <vector>
#include <numeric>

int main() {
    int n, ideal = 0;
    std::cin >> n;

    std::vector<int> list(n);

    for (int i = 0; i < n; i++) std::cin >> list[i];
    
    ideal = (std::accumulate(list.begin(), list.end(), 0))/n;

    for (int i = 0; i < n; i++) {
        std::cout << (ideal - list[i]) << std::endl;
    };
}