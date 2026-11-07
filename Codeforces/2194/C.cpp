#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MOD = 1e9+7;

void solve() {
    int n, k; cin >> n >> k;

    vector<vector<bool>> exist(n, vector<bool>(26));

    for (int i=0; i<k; ++i) {
        string s; cin >> s;

        for (int j=0; j<n; ++j) {
            char c = s[j];
            exist[j][c - 'a'] = true;
        }
    }

    vector<int> divisors;
    for (int i=1; i*i<=n; ++i) {
        if (n % i == 0) {
            divisors.push_back(i);
            divisors.push_back(n/i);
        }
    }
    sort(divisors.begin(), divisors.end());

    for (int divisor: divisors) {
        for (int i=0; i<divisor; ++i) {
            
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();
}