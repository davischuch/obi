#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>

int main() {
    int n, max = 0, res = 0;
    std::cin >> n;

    std::vector<int> list(n + 1);
    std::set<int> set;

    for (int i = 1; i <= n; i++) {
        int aux;
        std::cin >> aux;
        list[i] = aux;
        set.emplace(aux);
        max = std::max(max, aux);
    }
    
    bool loop = true;
    int s = *set.begin();
    while (loop) {
        if (s != max) {
            for (int l = 1, r = l; r <= n && l <= n; l++) {
                if (list[l] == s) {
                    r = l;
                    while (list[r] == s && r <= n) {
                        list[r] = list[r] + 1;
                        r++;
                        if (list[r] != s) {
                            res++;
                        }
                    }
                }
            }
            set.erase(s);
            s++;
        } else {
            loop = false;
        }
    }

    std::cout << res;
}