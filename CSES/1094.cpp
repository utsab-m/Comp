#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    ll changes = 0;

    ll prev;
    cin >> prev;

    for (int i = 1; i < n; i++) {
        ll cur;
        cin >> cur;

        if (cur < prev) {
            changes += prev - cur;
        } else {
            prev = cur;
        }
    }

    cout << changes;
}