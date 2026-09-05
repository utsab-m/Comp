#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MOD = 1e9+7;
const ll MAXN = 1e12;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // check if sqrt is prime
    int lim = sqrt(MAXN);

    vector<bool> comp(lim+1);
    set<ll> tprimes;

    for (int i = 2; i <= lim; ++i) {
        if (!comp[i]) {
            tprimes.insert(i * i);
            for (int j = i * i; j <= lim; j += i) {
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