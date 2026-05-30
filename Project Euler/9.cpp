#include "bits/stdc++.h"
using namespace std;
using ll = long long;

bool is_triplet(int a, int b, int c) {
    return a*a + b*b == c*c;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int a = 1; a <= 498; a++) {
        for (int b = a; b <= 1000-a; b++) {
            int c = 1000-a-b;
            if (is_triplet(a, b, c)) {
                cout << a * b * c << "\n";
            }
        }
    }
}