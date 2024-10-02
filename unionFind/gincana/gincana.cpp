#include <iostream>

int n, m, parent[1000], weight[1000];

int find(int x) {
	if (parent[x] == x) {
		return x;
	} else {
		return find(parent[x]);
	}
}

int join(int x, int y) {
	x = find(x);
	y = find(y);

	if (x == y) {
		return 0;
	} else {
		return parent[x] = y;
	}

}

int main() {
	int output = 0;
	std::cin >> n >> m;

	for (int i = 1; i <= n; i++) parent[i] = i;

	for (int i = 0; i < m; i++) {
		int a, b;
		std::cin >> a >> b;

		join(a, b);
	}

	for (int i = 1; i <= n; i++) {
		if (parent[i] == i) {
			output++;
		}
	}

	std::cout << output;
}