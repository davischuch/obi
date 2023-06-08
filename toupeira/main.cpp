#include <iostream>
#include <vector>
#include <map>

int main() {
	int s, t, p, output = 0;
	std::cin >> s >> t;

	std::map<int, std::vector<int>> list;
	std::vector<int> currentList;
	std::vector<int>::iterator it;

	for (int i = 0; i < t; i++) {
		int a, b;
		std::cin >> a >> b;

		if (list[a].empty()) {
			currentList.push_back(b);
			
			list[a] = currentList;
			currentList.clear();
		} else {
			currentList = list[a];
			currentList.push_back(b);

			list[a] = currentList;
			currentList.clear();
		}

		if (list[b].empty()) {
			currentList.push_back(a);

			list[b] = currentList;
			currentList.clear();
		}
		else {
			currentList = list[b];
			currentList.push_back(a);

			list[b] = currentList;
			currentList.clear();
		}
	}

	std::cin >> p;

	for (int i = 0; i < p; i++) {
		int n;
		std::cin >> n;
		
		bool stats = true;	

		int ant = -1;
		int cur = -1;

		for (int j = 0; j < n; j++) {
			std::cin >> cur;
			
			if (j > 0) {
				it = std::find(list[ant].begin(), list[ant].end(), cur);
				if (it == list[ant].end()) {
					stats = false;
				}
			}
			
			ant = cur;
		}

		if (stats == true) output++;
	}
	std::cout << output;
}