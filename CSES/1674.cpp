#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MOD = 1e9+7;
const int MAX = 2e5+5;
vector<int> children[MAX];
int numChildren[MAX];

void dfs(int node) {
    if (children[node].empty()) {
        numChildren[node] = 0;
        return;
    } else {
        numChildren[node] = children[node].size();
        for (int child: children[node]) {
            dfs(child);
            numChildren[node] += numChildren[child];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 2; i <= n; ++i) {
        int x;
        cin >> x;
        children[x].push_back(i);
    }

    dfs(1);

    for (int i = 1; i <= n; ++i) {
        cout << numChildren[i] << ' ';
    }

}