#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void no() {cout << "NO" << '\n';}
void yes() {cout << "YES" << '\n';}

bool check(string& s1, string& s2, map<char, char>& s1map, map<char, char>& s2map) {
    bool s1true = true, s2true = true;
    for (int i=0; i<s1.size(); ++i) {
        char c1 = s1[i], c2 = s2[i];
        if (s1map.find(c2) == s1map.end()) s1map[c2] = c2;
        if (s2map.find(c2) == s2map.end()) s2map[c2] = c2;
        s1true = s1true && s1map[c1] == s1map[c2];
        s2true = s2true && s2map[c1] == s2map[c2];
    }
    return s1true || s2true;
}

void solve() {
    string s1, s2, s3; cin >> s1 >> s2 >> s3;
    int m=s1.size(), n=s2.size(), k=s3.size();

    if (m != n) {
        no();
        return;
    }

    map<char, char> s1map, s2map;

    for (int i=0; i<m; ++i) {
        char x=s1[i], y=s2[i];
        s1map[x] = y;
        s1map[y] = y;
        s2map[y] = x;
        s2map[x] = x;
    }

    if (!check(s1, s2, s1map, s2map)) {
        no();
        return;
    }

    if (n != k) {
        yes();
        return;
    }

    if (check(s1, s3, s1map, s2map)) {
        no();
    } else {
        yes();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();
}