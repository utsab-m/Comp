#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    queue<int> q;
    for (int i = 1; i <= n; i++) q.push(i);

    bool remove = false;

    while (!q.empty()) {
        int num = q.front();
        q.pop();
        if (!remove) q.push(num);
        else cout << num << " ";
        remove = !remove;
    }
}