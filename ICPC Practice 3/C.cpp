#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void print(vector<int> v) {
    for (int i: v) cout << i << ' ';
}

void solve() {
    int n, m; cin >> n >> m;

    set<vector<int>> st;

    for (int i=0; i<n; ++i) {
        vector<int> nums(m);
        for (int j=0; j<m; ++j) cin >> nums[j];
        st.insert(nums);
    }

    if (n == 1) {
        for (int i=0; i<m/2; ++i) {
            cout << (*st.begin())[i] << ' ';
        }
        cout << '\n';
        return;
    }

    if (n % 2 == 0) {
        for (auto it = st.begin(); it != st.end(); ++it) {
            auto v = *it;
            for (int i=0; i<m; ++i) {
                cout << v[i] << ' ';
            }
        }
    } else {
        map<vector<int>, vector<int>> begToEnd;

        for (auto it = st.begin(); it != st.end(); ++it) {
            auto v = *it;
            vector<int> v1(m/2), v2(m/2);
            for (int i=0; i<m/2; ++i) {
                v1[i] = v[i];
                v2[i] = v[i+m/2];
            }
            begToEnd[v1] = v2;
        }

        auto f = *begToEnd.begin();
        vector<int> curr = f.second;
        print(f.first);
        print(f.second);

        for (int i=0; i<n-2; ++i) {
            print(begToEnd[curr]);
            curr = begToEnd[curr];
        }
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();
}