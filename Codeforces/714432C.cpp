#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const ll MAXN = 1e12;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // check if sqrt is prime
    ll limit = round(sqrt(MAXN));
    vector<bool> comp(limit+1, false);
    
    comp[0] = comp[1] = true;

    for (ll i = 2; i * i <= MAXN; ++i) {
        if (!comp[i]) {
            for (ll j = i * i; j <= limit; j += i) {
                comp[j] = true;
            }
        }
    }

    int n;
    cin >> n;

    while (n--) {
        ll x;
        cin >> x;
        
        ll root = round(sqrt(x));

        if (root * root == x && !comp[root]) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
}