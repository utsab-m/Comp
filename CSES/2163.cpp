#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int bit[200005];
int n;

void update(int i, int val) {
    for (; i <= n; i += (i & -i)) bit[i] += val;
}

int query(int i) {
    int sum = 0;
    for (; i > 0; i -= (i & -i)) {
        sum += bit[i];
    }
    return sum;
}

int find_kth(int k) {
    int idx = 0;
    for (int i = 1 << 18; i > 0; i >>= 1) {
        if (idx + i <= n && bit[idx + i] < k) {
            idx += i;
            k -= bit[idx];
        }
    }
    return idx + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int k;
    cin >> n >> k;

    for (int i = 1; i <= n; i++) update(i, 1);

    int current_pos = 0;
    for (int i = n; i > 0; i--) {
        current_pos = (current_pos + k) % i;

        int actual_val = find_kth(current_pos + 1);

        cout << actual_val << " ";

        update(actual_val, -1);
    }
}