#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MOD = 1e9+7;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    map<char, char> mp;
    for (char c='a'; c<='z'; ++c) mp[c] = c;

    int ans = 0;
    int l=(n-1)/2, r=n/2;

    vector<pair<char, char>> pairs;

    while (l >= 0 && r < n) {
        char x=s[l], y=s[r];
        pairs.push_back({max(x, y), min(x, y)});
        --l; ++r;
    }

    sort(pairs.rbegin(), pairs.rend());

    for (int i=0; i<pairs.size(); ++i) {
        auto pr = pairs[i];

        int x = pr.first, y = pr.second;
        while (x != mp[x]) x = mp[x];
        while (y != mp[y]) y = mp[y];

        for (char c=y; c<=x; ++c) {
            mp[c] = y;
        }
        ans += x-y;
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();
}