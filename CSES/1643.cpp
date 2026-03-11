#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    ll maxSum = LLONG_MIN, curr = 0;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        if (curr < 0) {
            curr = x;
        } else {
            curr += x;
        }
        maxSum = max(curr, maxSum);
    }

    cout << maxSum << "\n";
}