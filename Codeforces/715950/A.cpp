#include "bits/stdc++.h"
#include <array>
using namespace std;
using ll = long long;

const int MOD = 1e9+7;

int char_to_int(char c) {
    if ('0' <= c && c <= '9') return c - '0';
    else return c - 'a' + 10; 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    string s;
    cin >> s;

    s = " " + s;

    vector<vector<int>> adj(n+1);
    for (int i = 0; i < n-1; ++i) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<array<int, 16>> trie;
    array<int, 16> empty_node;
    empty_node.fill(-1);
    trie.push_back(empty_node);

    ll unique_guids = 0;

    auto dfs = [&](auto& self, int u, int p, int trie_idx) -> void {
        int c = char_to_int(s[u]);

        if (trie[trie_idx][c] == -1) {
            trie[trie_idx][c] = trie.size();
            trie.push_back(empty_node);
            ++unique_guids;
        }

        int next_trie_idx = trie[trie_idx][c];

        for (int v: adj[u]) {
            if (v != p) {
                self(self, v, u, next_trie_idx);
            }
        }
    };

    for (int i = 1; i <= n; ++i) {
        dfs(dfs, i, 0, 0);
    }

    cout << unique_guids << '\n';
}