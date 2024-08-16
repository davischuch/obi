#include <iostream>
#include <math.h>

int main() {
    int n;
    std::cin >> n;

    int total = pow(n, 3);
    int zero = pow((n - 2), 3);
    int dois = (n - 2)*12;
    int um = total - zero - dois - 8;

    std::cout << zero << std::endl;
    std::cout << um << std::endl;
    std::cout << dois << std::endl;
    std::cout << 8 << std::endl;
}