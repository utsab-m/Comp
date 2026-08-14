#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MOD = 1e9+7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    vector<int> count(26);

    bool odd = false;

    for (char c: s) ++count[c - 'A'];
    for (int c: count) {
        if (c % 2 == 1) {
            if (odd) {
                cout << "NO SOLUTION" << '\n';
                return 0;
            } else {
                odd = true;
            }
        }
    }

    string res;
    char oddChar;

    for (int i = 0; i < 26; ++i) {
        char c = 'A' + i;
        int cnt = count[i];

        if (cnt % 2 == 0) {
            res += string(cnt / 2, c);
        } else oddChar = c;
    }
    
    string t(res.rbegin(), res.rend());

    cout << (odd ? res + string(count[oddChar-'A'], oddChar) + t : res + t) << '\n';
}