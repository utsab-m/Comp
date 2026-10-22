#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MOD = 1e9+7;

void solve() {
    string s; cin >> s;
    int n=s.size();

    ll ans = 1;

    // check for 010 -> 0 or 101 -> 1
    for (int i=1; i<n-1; ++i) {
        if (s[i-1] != s[i] && s[i] != s[i+1]) {
            ++ans;
            break;
        }
    }

    // check for 111 -> 101 or 000 -> 010
    for (int i=1; i<n-1; ++i) {
        if (s[i-1] == s[i] && s[i] == s[i+1]) {
            ++ans;
            break;
        }
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();
}