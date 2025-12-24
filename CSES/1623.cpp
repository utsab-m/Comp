#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void print(string s, vector<ll>& v, ll sum) {
    cout << s << sum << "\n";
    for (ll n: v) cout << n << " \n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll left = 0;
    
    int n;
    cin >> n;

    vector<ll> p;

    ll c;
    ll total = 0;

    while (n--) {
        cin >> c;
        p.push_back(c);
        total += c;
    }

    sort(p.begin(), p.end());

    for (int x: p) cout << x << " ";

    vector<ll> l, r;

    for (int i = p.size()-1; i>=0; i--) {
        ll x = p[i];
        if (left + x <= total / 2) {
            left += x;
            l.push_back(x);
        } else r.push_back(x);
    }

    cout << (total - left) - left << "\n";

    print("Left: ", l, left);
    print("Right: ", r, total-left  );
}