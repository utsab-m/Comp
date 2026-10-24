#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;
using ll = long long;

const double PI = acos(-1.0);

struct Point {
    ll x, y;
};

void solve() {
    int n, k;
    double d;
    if (!(cin >> n >> k >> d)) return;

    vector<Point> pts(n);
    for (int i = 0; i < n; ++i) {
        cin >> pts[i].x >> pts[i].y;
    }

    if (k == 1) {
        cout << fixed << setprecision(10) << PI * d << '\n';
        return;
    }

    vector<double> prob(n + 1, 0.0);
    prob[k - 2] = 1.0;
    
    for (int i = 0; i < k; ++i) {
        prob[k - 2] *= (double)(k - i) / (n - i);
    }
    for (int L = k - 1; L <= n; ++L) {
        prob[L] = prob[L - 1] * (double)L / (L - k + 2);
    }

    double expected_hull_len = 0.0;

    for (int i = 0; i < n; ++i) {
        vector<int> sorted_indices;
        sorted_indices.reserve(n - 1);
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;
            sorted_indices.push_back(j);
        }

        auto half = [&](int j) {
            ll dy = pts[j].y - pts[i].y;
            if (dy != 0) return dy > 0;
            return j > i; 
        };

        auto is_left_func = [&](int j, int m) {
            ll dx_j = pts[j].x - pts[i].x;
            ll dy_j = pts[j].y - pts[i].y;
            ll dx_m = pts[m].x - pts[i].x;
            ll dy_m = pts[m].y - pts[i].y;
            
            ll C = dx_j * dy_m - dy_j * dx_m;
            if (C != 0) return C > 0;
            
            ll C1 = (ll)(j - i) * dy_m - (ll)(m - i) * dy_j;
            if (C1 != 0) return C1 > 0;
            
            ll C2 = dx_j * ((ll)m * m - (ll)i * i) - dx_m * ((ll)j * j - (ll)i * i);
            if (C2 != 0) return C2 > 0;
            
            ll C3 = (ll)(j - i) * (m - i) * (m - j);
            return C3 > 0;
        };

        sort(sorted_indices.begin(), sorted_indices.end(), [&](int m1, int m2) {
            bool h1 = half(m1);
            bool h2 = half(m2);
            if (h1 != h2) return h1 > h2;
            return is_left_func(m1, m2);
        });

        int m_sz = n - 1;
        int r = 0;
        
        for (int k_idx = 0; k_idx < m_sz; ++k_idx) {
            int j = sorted_indices[k_idx];
            r = max(r, k_idx + 1);
            
            while (r < k_idx + m_sz) {
                int curr_m = sorted_indices[r % m_sz];
                if (is_left_func(j, curr_m)) {
                    r++;
                } else {
                    break;
                }
            }
            
            int L = r - k_idx - 1;
            if (L >= k - 2) {
                double dist = hypot(pts[j].x - pts[i].x, pts[j].y - pts[i].y);
                expected_hull_len += dist * prob[L];
            }
        }
    }

    cout << fixed << setprecision(10) << expected_hull_len + (PI * d) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    return 0;
}