#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;

    vector<int> prices(n), pages(n);

    for (int& price: prices) cin >> price;
    for (int& page: pages) cin >> page;

    vector<vector<int>> dp(n+1, vector<int>(x+1));

    for (int books = 0; books <= n; books++) {
        for (int maxPrice = 0; maxPrice <= x; maxPrice++) {
            if (books == 0 || maxPrice == 0) dp[books][maxPrice] = 0;
            else {
                int price = prices[books-1], numPages = pages[books-1];
                int pick = 0;
                if (price <= maxPrice) pick = numPages + dp[books-1][maxPrice-price];
                int doNotPick = dp[books-1][maxPrice];
                dp[books][maxPrice] = max(pick, doNotPick);
            }
        }
    }

    cout << dp[n][x] << "\n";
}