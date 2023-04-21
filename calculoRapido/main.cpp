#include <iostream>
#include <string>
#include <vector>
#include <numeric>

int main() {
	int desiredSum;
	std::cin >> desiredSum;

	std::string firstNum;
	std::string	secondNum;
	
	std::cin >> firstNum;
	std::cin >> secondNum;
	
	std::vector<int> allSums(0);

	for (int i = std::stoi(firstNum); i <= std::stoi(secondNum); i++) {
		std::string currentNumber = std::to_string(i);
		int sizeOfSecondNumber = currentNumber.size();

		int currentSum = std::accumulate(currentNumber.begin(), currentNumber.end(), 0);
		int cleanSum = currentSum - (48 * sizeOfSecondNumber);

		if (cleanSum == desiredSum) {
			allSums.push_back(cleanSum);
		}
	}

	std::cout << allSums.size();
}