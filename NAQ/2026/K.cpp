#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MOD = 1e9+7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    vector<int> favNumbers;

    int numDigits=1;
    while (numDigits <= 9) {
        for (int start=1; start<=9-numDigits+1; ++start) {
            int num = 0, ten=1;
            for (int end=start+numDigits-1; end>=start; --end) {
                num += end * ten;
                ten*=10;
            }
            favNumbers.push_back(num);
        }
        ++numDigits;
    }

    while (t--) {
        int n;
        cin >> n;

        for (int num: favNumbers) {
            if (num >= n) {
                cout << num << '\n';
                break;
            }
        }
    }
}