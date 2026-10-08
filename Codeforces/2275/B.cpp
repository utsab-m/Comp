#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MOD = 1e9+7;

void solve() {
    int n; cin >> n;
    string s; cin >> s;

    stack<int> mem;
    set<int> printed;

    int i = 1;
    for (char c: s) {
        int x = c - '0';

        if (x == 1) {
            mem.push(i);
        } else if (x == 2 && !mem.empty()) {
            int top = mem.top(); mem.pop();
            printed.insert(top);
        } else {
            printed.insert(i);
        }
        ++i;
    }

    int k = n - printed.size();

    cout << k << '\n';
    if (k == 0) return;

    for (int i=1; i<=n; ++i) {
        if (printed.find(i) == printed.end()) {
            cout << i << ' ';
        }
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();
}