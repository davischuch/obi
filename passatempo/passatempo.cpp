#include <iostream>
#include <string>
#include <set>
#include <map>

int main() {
	int l, c;
	int valLines[110], valColums[110];
	std::string matrix[110][110];
	std::map<std::string, int> knownVars;
	std::set<std::string> vars;

	std::cin >> l >> c;

	for (int i = 1; i <= l; i++) {
		for (int j = 1; j <= c; j++) {
			std::cin >> matrix[i][j];
			vars.insert(matrix[i][j]);
		}
		std::cin >> valLines[i];
	}
	for (int i = 1; i <= c; i++) std::cin >> valColums[i];

	while (knownVars.size() < vars.size()) {
		//linhas
		for (int i = 1; i <= l; i++) {
			bool ok = true;
			int qtd = 0, knowValue = 0;
			std::string comparison;

			for (int j = 1; j <= c; j++) {
				if (knownVars.find(matrix[i][j]) == knownVars.end()) { //não tem nenhuma variável conhecida
					if (qtd == 0) {
						qtd++;
						comparison = matrix[i][j];
					} else if (comparison == matrix[i][j]) {
						qtd++;
					} else {
						ok = false;
						break;
					}
				}
				else if (knownVars.find(matrix[i][j]) != knownVars.end()) { //tem alguma variável conhecida
					knowValue += knownVars[matrix[i][j]];
				}

			}
			
			if (ok and qtd) { //calculo
				knownVars[comparison] = (valLines[i] - knowValue) / qtd;
			}
		}

		//colunas
		for (int j = 1; j <= c; j++) {
			bool ok = true;
			int qtd = 0, knownValue = 0;
			std::string comparison;
		
			for (int i = 1; i <= l; i++) {
				if (knownVars.find(matrix[i][j]) == knownVars.end()) {
					if (qtd == 0) {
						qtd++;
						comparison = matrix[i][j];
					}
					else if (comparison == matrix[i][j]) {
						qtd++;
					}
					else {
						ok = false;
						break;
					}
				}
				else if (knownVars.find(matrix[i][j]) != knownVars.end()) {
					knownValue += knownVars[matrix[i][j]];
				}

			}
			
			if (ok and qtd) {
				knownVars[comparison] = (valColums[j] - knownValue) / qtd;
			}
		}
	}

	for (auto i : knownVars) {
		std::cout << i.first << " " << i.second << std::endl;
	}
} 