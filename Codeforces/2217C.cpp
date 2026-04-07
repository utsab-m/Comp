#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, m, a, b;
        cin >> n >> m >> a >> b;

        set<pair<int, int>> rightVis;
        rightVis.insert({1, 1});

        queue<pair<pair<int, int>, string>> q;
        q.push({{1, b % m + 1}, "right"});

        while (!q.empty()) {
            int k = q.size();

            for (int l = 0; l < k; l++) {
                auto move = q.front();
                auto pos = move.first;
                string dir = move.second;
                q.pop();   
                rightVis.insert(pos);

                int i = pos.first, j = pos.second;
                string nextDir;

                if (dir == "right") {
                    i = (i + a - 1) % n + 1;
                    nextDir = "down";
                } else {
                    j = (j + b - 1) % m + 1;
                    nextDir = "right";
                }
                pair<int, int> nextMove = {i, j};
                if (rightVis.find(nextMove) == rightVis.end()) q.push({{i, j}, nextDir});
                else q = queue<pair<pair<int, int>, string>>();
            }
        }

        set<pair<int, int>> downVis;
        downVis.insert({1, 1});

        q.push({{a % n + 1, 1}, "down"});

        while (!q.empty()) {
            int k = q.size();

            for (int l = 0; l < k; l++) {
                auto move = q.front();
                auto pos = move.first;
                string dir = move.second;
                q.pop();   
                downVis.insert(pos);

                int i = pos.first, j = pos.second;
                string nextDir;

                if (dir == "right") {
                    i = (i + a - 1) % n + 1;
                    nextDir = "down";
                } else {
                    j = (j + b - 1) % m + 1;
                    nextDir = "right";
                }
                pair<int, int> nextMove = {i, j};
                if (downVis.find(nextMove) == downVis.end()) q.push({{i, j}, nextDir});
            }
        }

        if (downVis.size() == n*m || rightVis.size() == n*m) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

}