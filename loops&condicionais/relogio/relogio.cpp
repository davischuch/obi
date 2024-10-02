#include <iostream>

int main() {
	unsigned int h, m, s, t;
	std::cin >> h >> m >> s >> t;

	s += t;
	while (s >= 60) {
		s = s - 60;
		m++;
	}

	while (m >= 60) {
		m = m - 60;
		h++;
	}

	while (h >= 24) {
		h = h - 24;
	}

	std::cout << h << std::endl;
	std::cout << m << std::endl;
	std::cout << s << std::endl;
}