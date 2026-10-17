#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    int MAX_NUM=0, MIN_NUM=1e9+1;

    for (int i=1; i<=n; ++i) {
        int p; cin >> p;
        MAX_NUM = max(MAX_NUM, p);
        MIN_NUM = min(MIN_NUM, p);
    }

    cout << MAX_NUM - MIN_NUM << '\n';
}