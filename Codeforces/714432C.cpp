#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MOD = 1e9+7;
const ll MAXN = 1e12;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // check if sqrt is prime
    vector<bool> comp((int)1e6+1);
    set<ll> tprimes;

    cout << comp.size();

    for (ll i = 2; i * i <= MAXN; ++i) {
        if (!comp[i]) {
            tprimes.insert(i * i);
            for (ll j = i * i; j * j < MAXN; j += i) {
                comp[j] = true;
            }
        }
    }

    int n;
    cin >> n;

    while (n--) {
        ll x;
        cin >> x;
        bool is_tprime = tprimes.find(x) != tprimes.end();

        if (is_tprime) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
}