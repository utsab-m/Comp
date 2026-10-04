#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MOD = 1e9+7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, q, g;
        cin >> n >> q >> g;
        vector<set<int>> last_ppl(g+1);
        vector<int> last_genre(n+1);

        for (int i=0; i<q; ++i) {
            char type;
            cin >> type;

            if (type == 'P') {
                int s, a;
                cin >> s >> a;

                for (int j=0; j<a; ++j) {
                    int p;
                    cin >> p;

                    if (last_genre[p] != 0) {
                        last_ppl[last_genre[p]].erase(p);
                    }
                    last_genre[p] = s;
                    last_ppl[s].insert(p);
                }
            } else {
                int s;
                cin >> s;

                cout << last_ppl[s].size() << '\n';
            }
        }
    }
}