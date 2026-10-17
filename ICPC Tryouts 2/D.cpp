#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k; cin >> n >> k;

    int mex = 0;

    map<int, int> count;

    for (int i=1; i<=n; ++i) {
        int x; cin >> x;

        ++count[x];
    }

    for (auto pr: count) {
        if (mex == pr.first) ++mex;
    }

    // get rid of dupes
    for (auto pr: count) {
        if (k <= 0) break;
        int num = pr.first, val = pr.second;
        if (val > 1) {
            --count[num];
            if (count[num] == 0) count.erase(num);
            ++count[mex];
            while (count.find(mex) != count.end()) ++mex;
        }
    }

    while (k > 0) {
        auto last = prev(count.end());
        count.erase(last);
        ++count[mex];
        while (count.find(mex) != count.end()) ++mex;
        --k;
    }

    cout << mex << '\n';
}