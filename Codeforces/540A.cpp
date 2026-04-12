#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    string og, combo;
    cin >> og >> combo;

    int moves = 0;

    for (int i = 0; i < n; i++) {
        int a = og[i] - '0', b = combo[i] - '0';

        moves += min((10 + (a-b) % 10) % 10, (10 + (b-a) % 10) % 10);
    }

    cout << moves << "\n";
}