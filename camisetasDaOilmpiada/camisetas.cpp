#include <iostream>
#include <vector>

int main() {
	int numOfPremiados,
		pFeitas,
		pSolicitadas = 0,
		mFeitas,
		mSolicitadas = 0;
	std::vector<int> tamanhosSolicitados;

	std::cin >> numOfPremiados;

	for (int i = 0; i < numOfPremiados; i++) {
		int currentNumber;
		std::cin >> currentNumber;
		tamanhosSolicitados.push_back(currentNumber);
	}

	std::cin >> pFeitas;
	std::cin >> mFeitas;

	for (auto& i : tamanhosSolicitados) {
		switch (i) {
		case 1:
			pSolicitadas++;
			break;
		case 2:
			mSolicitadas++;
			break;
		default:
			break;
		}
	}

	if (pSolicitadas == pFeitas && mSolicitadas == mFeitas) {
		std::cout << "S";
	}
	else {
		std::cout << "N";
	}
}