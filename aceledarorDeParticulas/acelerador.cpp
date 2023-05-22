#include <iostream>

int main() {
	double input;
	int subtract, output, switchVar;
	std::cin >> input;

	input = input - 5;
	input = input / 8;

	subtract = input;
	input = input - subtract;
	switchVar = input / 0.125;

	switch (switchVar) {
	case 1:
		output = 1;
		break;
	case 2:
		output = 2;
		break;
	case 3:
		output = 3;
		break;
	default:
		output = 0;
		break;
	}

	std::cout << output;
}