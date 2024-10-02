#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

constexpr long long maxn = 5e4 + 10;
std::vector<std::pair<int, int>> grafo[maxn];
int output = 0;

std::pair<int, int> dfs(int vertice, int verticeAnterior) {
	int bigOne = 0, bigZero = 0;

	for (auto value : grafo[vertice]) {
		int verticeAdj = value.first, size = value.second;

		if (verticeAdj == verticeAnterior) {
			continue;
		}

		if (size == 1) {
			bigOne = std::max(bigOne, dfs(verticeAdj, vertice).second);
		}
		else if (size == 0) {
			bigZero = std::max(bigZero, dfs(verticeAdj, vertice).first);
		}
	}
	output = std::max(output, bigOne + bigZero + 1);
	return std::make_pair(bigOne + 1, bigZero + 1);
}

int main() {
	int n;
	std::cin >> n;

	for (int i = 1; i < n; i++) {
		int vertice, verticeAdj, size;
		std::cin >> vertice >> verticeAdj >> size;
		grafo[vertice].push_back({ verticeAdj, size });
		grafo[verticeAdj].push_back({ vertice, size });
	}

	dfs(1, -1);

	std::cout << output;
}