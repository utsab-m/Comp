#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MOD = 1e9+7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;

    vector<int> weights(n);
    for (int& weight: weights) cin >> weight;

    vector<pair<int, int>> dp(1 << n);
    dp[0] = {1, 0};

    for (int mask = 1; mask < (1 << n); ++mask) {

    }
}