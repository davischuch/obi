#include <iostream>
#include <vector>

int main() {
    int n, d, result = 0;
    std::cin >> n >> d;
    std::vector<int> pieces;

    for (int i = 0; i < n; i++) {
        int aux;
        std::cin >> aux;
        pieces.push_back(aux);
    }

    int soma = pieces[0];
    for (int l = 0, r = 0; l < n;) {
        if (soma < d) {
            r++;
            if (r == n) {
                r = 0;
            }
            soma+=pieces[r];
        } else if (soma > d) {
            soma-=pieces[l];
            l++;
        } else if (soma == d) {
            result++;
            r++;
            if (r == n) {
                r = 0;
            }
            soma+=pieces[r];
            soma-=pieces[l];
            l++;
        }
    }

    std::cout << result;
}