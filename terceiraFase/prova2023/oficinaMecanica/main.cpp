#include <iostream>
#include <queue>
#include <map>
#include <algorithm>

struct mech {
    int time, tg, att;
};

int main() {
    int n, m;
    std::cin >> n >> m;

    std::priority_queue<int, std::vector<int>, std::greater<int>> cars;
    std::map<int, mech, std::greater<int>> mechanics;

    for (int i = 0; i < n; i++) {
        int aux;
        std::cin >> aux;
        cars.push(aux);
    }
    for (int i = 0; i < m; i++) {
        int aux;
        std::cin >> aux;
        mechanics[aux] = {0, 0, 0};
    }

    while(!cars.empty()) {
        for (auto & m : mechanics) {
            int current;
            current = cars.top();
            cars.pop();
            
            if (m.second.att == 0) {
                m.second.tg = current*m.first;
                m.second.att++;
                continue;
            } else {
                m.second.time += m.second.tg;
                m.second.tg += current*m.first;
                m.second.att++;
            }
        }
    }

    int total = 0;
    for (auto & m : mechanics) {
        total += m.second.time;
    }
    std::cout << total;
}