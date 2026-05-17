#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<int, int>> heights(n);
    vector<int> dp(n), pge(n), nge(n);

    for (int i = 0; i < n; i++) {
        cin >> heights[i].first;
        heights[i].second = i;
    }

    stack<int> st;

    for (int i = 0; i < n; ++i) {
        while (!st.empty() && heights[st.top()].first <= heights[i].first) st.pop();
        if (st.empty()) pge[i] = -1;
        if (!st.empty()) pge[i] = st.top();
        st.push(i);
    }

    while (!st.empty()) st.pop();

    for (int i = n-1; i >= 0; --i) {
        while (!st.empty() && heights[st.top()].first <= heights[i].first) st.pop();
        if (st.empty()) nge[i] = -1;
        if (!st.empty()) nge[i] = st.top();
        st.push(i);
    }

    int mx = 1;

    sort(heights.rbegin(), heights.rend());

    for (int idx = 0; idx < n; ++idx) {
        int i = heights[idx].second;
        dp[i] = max(dp[i], 1 + ((pge[i] != -1) ? dp[pge[i]] : 0));
        dp[i] = max(dp[i], 1 + ((nge[i] != -1) ? dp[nge[i]] : 0));
        mx = max(mx, dp[i]);
    }

    cout << mx << "\n";
}