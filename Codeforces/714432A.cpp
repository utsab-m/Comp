#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MOD = 1e9+7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int w;
    cin >> w;

    if (w % 2 == 0 && w > 2) {
        cout << "YES" << '\n';
    } else {
        cout << "NO" << '\n';
    }
}