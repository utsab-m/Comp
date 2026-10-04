#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MOD = 1e9+7;

void solve() {
    int n; cin >> n;
    string s; cin >> s;

    int z = 0, o = 0;
    for (int i=0; i<n; ++i) {z+=(s[i]=='0');}
    if (s[0]=='1') {cout << z << endl; return;}
    int aa = 1e9;
    for (int i=0; i<n; ++i) {
        o+=(s[i]=='1');
        z-=(s[i]=='0');
        aa = min(aa, o+z);
    }

    cout << aa << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {solve();}
}