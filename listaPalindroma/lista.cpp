#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int n;
	std::vector<int> vector;
	std::cin >> n;

	for (int i = 0; i < n; i++) {
		int currentNumber;
		std::cin >> currentNumber;
		vector.push_back(currentNumber);
	}

	int r = 0, l = n - 1, output = 0;

	while (r < l) {
		if (vector[r] == vector[l]) {
			r++;
			l--;
			continue;
		} else if (vector[r] > vector[l]) {
			vector[l - 1] += vector[l];
			l--;
			output++;
		} else if (vector[r] < vector[l]) {
			vector[r + 1] += vector[r];
			r++;
			output++;
		}
	}

	std::cout << output;
}