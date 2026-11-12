#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    vector<int> digits(n);
    for (int i=0; i<n; ++i) cin >> digits[i];

    for (int i=0; i<n; ++i) {
        int k; cin >> k;
        string seq; cin >> seq;

        for (char c: seq) {
            int whatToAdd;
            if (c == 'D') {
                whatToAdd = 1;
            } else {
                whatToAdd = -1;
            }
            (((digits[i] += whatToAdd) %= 10) += 10) %= 10;
        }
    }

    for (int digit: digits) cout << digit << ' ';
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();
}