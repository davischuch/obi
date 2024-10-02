#include <iostream>

int main() {
    int v, a, f, p;
    std::cin >> v >> a >> f >> p;

    if (a + f + p <= v) {
        std::cout << 3;
    }
    else if (a + f <= v || a + p <= v || p + f <= v) {
        std::cout << 2;
    }
    else if (a <= v || f <= v || p <= v) {
        std::cout << 1;
    }
    else {
        std::cout << 0;
    }
}