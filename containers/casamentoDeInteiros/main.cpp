#include <iostream>
#include <deque>
#include <algorithm>
#include <complex>
#include <stdlib.h>

int main() {
    int A = 0, B = 0, apos = 0, bpos = 0, apow = 0, bpow = 0;
    std::string a, b;
    std::cin >> a >> b;

    apos = a.size() - 1, bpos = b.size() - 1;

    for (int i = 0; i < std::max(a.size(), b.size()); i++, bpos--, apos--) {
        if (i >= std::min(a.size(), b.size())) {
            if (i >= a.size()) {
                B += (b[bpos] - 48) * std::pow(10, bpow);
                bpow++;
            }
            if (i >= b.size()) {
                A += (a[apos] - 48) * std::pow(10, apow);
                apow++;
            }
            continue;
        } else {
            if (a[apos] > b[bpos]) {
                A += (a[apos] - 48) * std::pow(10, apow);
                apow++;
            } else if (a[apos] < b[bpos]) {
                B += (b[bpos] - 48) * std::pow(10, bpow);
                bpow++;
            } else {
                A += (a[apos] - 48) * std::pow(10, apow);
                apow++;
                B += (b[bpos] - 48) * std::pow(10, bpow);
                bpow++;
            }
        }
    }
    if (A == 0 && apow == 0) {
        A = -1;
    }
    if (B == 0 && bpow == 0) {
        B = -1;
    }

    std::cout << std::min(A, B) << " " << std::max(A, B);
}