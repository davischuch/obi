#include <iostream>

int main() {
    int a, b, x = -1, y = -1;
    std::cin >> a >> b;

    int c = ((a - 4)/2) - 1;

    for (int l = 1; l <= b; l++, c--) {
        if (c*l == b && (2*l) + (2*c) + 4 == a) {
            std::cout << l + 2 << " " << c + 2;
            return 0;
        }
    }

    std::cout << y << " " << x;
    return 0;
}