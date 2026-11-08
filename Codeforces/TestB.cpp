#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    int count = 0;
    set<char> ch;

    for (char c: s) {
        if (ch.count(c)) {
            ++count;
        } else {
            count += 2;
            ch.insert(c);
        }
    }

    cout << count << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();
}