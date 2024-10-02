#include <iostream>
#include <vector>
#include <numeric>

int main() {
	std::vector<int> correctBossNumbers(0);
	int currentNumber;

	int numberOfLines;
	std::cin >> numberOfLines;


	for (int i = 0; i < numberOfLines; i++) {
		std::cin >> currentNumber;

		if (currentNumber == 0) {
			correctBossNumbers.pop_back();
		}
		else {
			correctBossNumbers.push_back(currentNumber);
		}

		if (i >= numberOfLines - 1) {
			std::cout << std::accumulate(correctBossNumbers.begin(), correctBossNumbers.end(), 0);
			break;
		}
	}
}
