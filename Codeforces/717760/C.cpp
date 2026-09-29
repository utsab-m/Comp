#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MOD = 1e9+7;

void solve() {
    int n;
    cin >> n;
    string str;
    cin >> str;

    map<ll, ll> count;
    count[0] = 1;

    vector<int> pref(n+1), s(n+1);
    ll ans = 0;

    for (int i=1; i<=n; ++i) {
        int num = str[i-1] - '0';
        pref[i] = pref[i-1] + num;
        s[i] = pref[i] - i;

        ans += count[s[i]];
        count[s[i]]++;
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}