#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> coins(n);

    for (int& coin: coins) cin >> coin;

    sort(coins.begin(), coins.end());

    ll coinSum = 1;

    for (int i = 0; i < n; i++) {
        if (coinSum < coins[i]) {
            break;
        } else {
            coinSum += coins[i];
        }
    }

    cout << coinSum << "\n";
}