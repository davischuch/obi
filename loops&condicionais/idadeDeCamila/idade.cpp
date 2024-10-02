#include <iostream>
#include <algorithm>
#include <vector>

int main() {
	int input[3];
	std::cin >> input[0];
	std::cin >> input[1];
	std::cin >> input[2];

	int n = sizeof(input) / sizeof(input[0]);
	std::sort(input, input + n);

	int idadeCamila = 0;

	for (int i = 0; i < 3; i++) {
		int ageMin = input[0];
		int ageMax = input[2];

		if (input[i] < ageMax) {
			if (input[i] > ageMin) {
				idadeCamila = input[i];
				break;
			}
		}
		if (i != 0) {
			if (input[i] == ageMin || ageMax) {
				idadeCamila = input[i];
				break;
			}
		}
	}
	std::cout << idadeCamila;
}