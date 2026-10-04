#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MOD = 1e9+7;

char print(bool test) {
    return test ? 'T' : 'F';
}

bool read(char c) {
    return c == 'T' ? true : false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    bool test = false;

    while (t--) {
        bool ans = true;
        char c;
        for (int i=1; i<=200; ++i) {
            cout << print(ans) << '\n';
            cin >> c;
            ans = !read(c);
        }
    }
}