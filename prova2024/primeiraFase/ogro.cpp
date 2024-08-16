#include <iostream>

int main() {
	int e, d;
	std::cin >> e >> d;

	if (e > d) {
		std::cout << e + d;
	}
	else {
		std::cout << 2 * (d - e);
	}
}