#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int INF = 1e9;
int n;
ll dp_1[5001][5001];
bool vis[5001][5001];
vector<ll> nums;

ll maxScore(int i, int j) {
    if (i > j) return 0;
    if (i == j) {
        dp_1[i][j] = nums[i];
        return dp_1[i][j];
    }
    if (vis[i][j]) return dp_1[i][j];

    ll choose_i = nums[i] + min(maxScore(i+2, j), maxScore(i+1, j-1));
    ll choose_j = nums[j] + min(maxScore(i, j-2), maxScore(i+1, j-1));

    vis[i][j] = true;
    return dp_1[i][j] = max(choose_i, choose_j);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        ll x;
        cin >> x;
        nums.push_back(x);
    }

    cout << maxScore(0, n-1) << "\n";
}