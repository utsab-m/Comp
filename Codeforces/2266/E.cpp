#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MOD = 1e9+7;
const int N = 2e5;

vector<bool> comp(N+12);
int gpf[N+12];

void solve() {
    int n, k; cin >> n >> k;

    map<int, int, greater<int>> count;

    for (int i=1; i<=n; ++i) {
        int a; cin >> a;
        ++count[a];
    }
    
    ll f = 0;
    for (const auto& [x, c]: count) {
        if (x <= k) break;
        
        int p = gpf[x];
        int q = x / p;
        count[q] += p * c;        
        f += c;
    }
    cout << f << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i=2; i<=N; ++i) {
        if (!comp[i]) {
            for (int j=i; j<=N; j+=i) {
                comp[j] = true;
                gpf[j] = i;
            }
        }
    }

    int t; cin >> t;
    while (t--) solve();
}