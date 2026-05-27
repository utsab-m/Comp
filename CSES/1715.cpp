#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int M = 1e9+7, MAX = 1000005;

ll power(ll b, ll e) {
    b %= M;

    ll res = 1;

    while (e > 0) { 
        if (e % 2 == 1) (res *= b) %= M;
        (b *= b) %= M;
        e /= 2;
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    int n = s.size();

    vector<ll> fact(n+1), invFact(n+1);
    fact[0] = 1;
    for (int i = 1; i <= n; i++) (fact[i] = i * fact[i-1]) %= M;
    invFact[n] = power(fact[n], M-2); 
    for (int i = n-1; i >= 0; i--) (invFact[i] = invFact[i+1] * (i+1)) %= M;

    vector<int> count(26);

    for (char c: s) count[c - 'a']++;

    ll res = fact[n];

    for (ll c: count) (res *= invFact[c]) %= M;

    cout << res << "\n";
}