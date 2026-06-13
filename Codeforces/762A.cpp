#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MOD = 1e9+7;

vector<ll> get_divisors(ll n) {
    vector<ll> divisors;
    for (ll i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            divisors.push_back(i);

            if (i != n / i) {
                divisors.push_back(n / i);
            }
        }
    }
    sort(divisors.begin(), divisors.end());
    return divisors;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, k;
    cin >> n >> k;

    vector<ll> divisors = get_divisors(n);

    if (divisors.size() < k) {
        cout << -1 << "\n";
    } else {
        cout << divisors[k-1] << "\n";
    }
}