#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll total = 0;
vector<ll> p;
ll sum = 0;
ll dist = INT_MAX;

void backtrack(int index) {
    if (index == p.size()) return;
    for (int i = index; i < p.size(); i++) {
        sum += p[i];
        ll d = abs((total - sum) - sum);
        dist = min(dist, d);
        backtrack(i+1);
        sum -= p[i];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll left = 0;
    
    int n;
    cin >> n;

    ll c;

    while (n--) {
        cin >> c;
        p.push_back(c);
        total += c;
    }

    sort(p.begin(), p.end());   

    backtrack(0);

    cout << dist << "\n";
}