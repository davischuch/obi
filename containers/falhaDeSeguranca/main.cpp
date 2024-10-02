#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

int main() {
    int n, res = 0;
    std::cin >> n;

    std::vector<std::string> list(n);
	std::map<std::string, int> sub;

    for (int i = 0; i < n; i++) {
        std::cin >> list[i];
		std::set<std::string> set;

		for (int j = 0; j < list[i].size(); j++) {
			std::string curr;
			for (int k = j; k < list[i].size(); k++) {
				curr.push_back(list[i][k]);
				set.insert(curr);
			}
		}
		for (auto & s : set) {
			sub[s]++;
		}
    }
	for (auto & l : list) {
		res += sub[l] - 1;
	}
    std::cout << res;
}