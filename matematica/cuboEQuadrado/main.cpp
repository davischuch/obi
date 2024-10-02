#include <iostream>
#include <cmath>
#include <cctype>

int main() {
    int a, b, res = 0;
    std::cin >> a >> b;

    for (int i = 1; std::pow(i, 3) <= b; i++) {
        if (std::pow(i, 3) < a) continue;
        int sq = (int)std::sqrt(std::pow(i, 3));
        if(std::pow(sq, 2) == std::pow(i, 3)) res++;
    }
    std::cout << res;
}