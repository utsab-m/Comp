#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void print(char c, ll n) {
    for (ll i = 0; i < n; i++) {
        cout << c;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s;
    cin >> s;

    vector<ll> count(26, 0);

    for (char c: s) count[c - 'A']++;

    ll oddCount = 0;
    char oddChar;

    for (int i = 0; i < 26; i++) {
        if (count[i] % 2 == 1) {
            oddCount++;
            oddChar = 'A' + i;
        }
    }

    if (oddCount > 1) {
        cout << "NO SOLUTION";
    } else {
        for (int i = 0; i < 26; i++) {
            if (count[i] % 2 == 0) {
                print('A' + i, count[i] / 2);
            }
        }

        print(oddChar, count[oddChar - 'A']);

        for (int i = 25; i >= 0; i--) {
            if (count[i] % 2 == 0) {
                print('A' + i, count[i] / 2);
            }
        }
    }

    cout << "\n";
}