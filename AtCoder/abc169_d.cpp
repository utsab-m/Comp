#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MOD = 1e9+7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N;
    cin >> N;

    ll total_operations = 0;

    for (ll i = 2; i * i <= N; ++i) {
        if (N % i == 0) {
            ll count = 0;
            while (N % i == 0) {
                ++count;
                N /= i;
            }

            ll current_needed = 1;
            while (count >= current_needed) {
                count -= current_needed;
                total_operations++;
                current_needed++;
            }
        }
    }

    if (N > 1) ++total_operations;

    cout << total_operations << '\n';
}