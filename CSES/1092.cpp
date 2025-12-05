#include "bits/stdc++.h"
#include <unordered_set>

using namespace std;
using ll = long long;

void print(unordered_set<ll>& set) {
    cout << set.size() << "\n";

    for (auto num: set) cout << num << " ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll n;
    cin >> n;

    ll totalSum = (n * (n + 1)) / 2;

    if (totalSum % 2 == 0) {
        cout << "YES" << "\n";
        
        unordered_set<ll> firstSet, secondSet;

        if (n % 2 == 1) {
            firstSet.insert(n);
            n--;
        }

        if (n % 2 == 0) {
            for (int i = 0; i < n / 4; i++) {
                firstSet.insert(i + 1);
                firstSet.insert(n - i);
            }
            for (int i = n / 4; i < n / 2; i++) {
                secondSet.insert(i + 1);
                secondSet.insert(n - i);
            }
        }

        print(firstSet);
        cout << "\n";
        print(secondSet);

    } else {
        cout << "NO";
    }
}