#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    ll sum = 0;
    vector<int> coins(n);
    for (int& coin: coins) {
        cin >> coin;
        sum += coin;
    }

    vector<bool> sums(sum+1);
    sums[0] = true;
    int count = 0;

    for (int coin: coins) {
        for (int i = sum; i - coin >= 0; i--) {
            if (sums[i-coin] && !sums[i]) {
                sums[i] = true;
                count++;
            }
        }
    }

    cout << count << "\n";
    for (int i = 1; i <= sum; i++) if (sums[i]) cout << i << " ";
}