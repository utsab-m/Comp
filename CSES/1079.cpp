#include "bits/stdc++.h"
using namespace std;

int binom(int a, int b) {
    int mod = 1e9 + 7;

    int num = 1;

    vector<int> nums;

    for (int i = 0; i < b; i++) {
        nums.push_back(a-i);
    }

    for (int i = 2; i <= b; i++) {
        for (int j = 0; j < b; j++) {
            if (nums[j] % i == 0) {
                nums[j] /= i;
                break;
            }
        }
    }

    for (int n: nums) num = (num % mod) *  (n % mod) % mod;

    return num;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int x;
    cin >> x;

    for (int i = 0; i < x; i++) {
        int a, b;
        cin >> a;
        cin >> b;
        cout << binom(a, b) << "\n";
    }
}