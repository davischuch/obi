//nao finalizado

#include <iostream>
#include <map>
#include <cmath>

std::map<int, int> cities;

int main() {
    int n, x, k, result = 0;
    std::cin >> n >> x >> k;

    for (int i = 0; i < n; i++) {
        int a, b;
        std::cin >> a >> b;
        cities[a] = b;
    }
    
    while (k > 0) {
        int dxm = 1000000000, cx = 0, cw = 0;
        bool foundCity = false;

        for (auto & c : cities) {
            int a, b;
            a = c.first;
            b = c.second;

            if (x != a) {
                int dx = abs(a - x);
                if ((dx <= dxm && b > cw && (k - dx > 0))) {
                    dxm = dx;
                    cx = a;
                    cw = b;
                    foundCity = true;
                }
            }
        }

        if (!foundCity) break;

        k -= dxm;
        if (k >= 0) {
            x = cx;
            result += cw;
            cities.erase(cx);
        }
    }

    std::cout << result;
}