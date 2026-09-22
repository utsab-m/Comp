#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MOD = 1e9+7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    double x1, y1, x2, y2, a; 
    if (!(cin >> x1 >> y1 >> x2 >> y2 >> a)) return 0;

    double dx = x2-x1, dy = y2-y1;
    double dist_foci = sqrt(dx*dx + dy*dy);

    double c = dist_foci / 2.0;
    double A = a / 2.0;
    double B = sqrt(A*A - c*c);

    double cx = (x1 + x2) / 2.0, cy = (y1 + y2) / 2.0;

    double cos_theta = 1.0, sin_theta = 0.0;

    if (dist_foci > 0) {
        cos_theta = dx / dist_foci;
        sin_theta = dy / dist_foci;
    }

    double delta_x = sqrt(A*A*cos_theta*cos_theta + B*B*sin_theta*sin_theta);
    double delta_y = sqrt(A*A*sin_theta*sin_theta + B*B*cos_theta*cos_theta);

    double x_low = cx - delta_x;
    double x_high = cx + delta_x;
    double y_low = cy - delta_y;
    double y_high = cy + delta_y;

    cout << fixed << setprecision(6);
    cout << x_low << ' ' << y_low << ' ' << x_high << ' ' << y_high << '\n';
}