#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MOD = 1e9+7;

vector<vector<ll>> mult(vector<vector<ll>>& A, vector<vector<ll>>& B) {
    vector<vector<ll>> C(6, vector<ll>(6));
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            for (int k = 0; k < 6; k++) {
                (C[i][j] += A[i][k] * B[k][j]) %= MOD;
            }
        }
    }
    return C;
}

vector<vector<ll>> power(vector<vector<ll>>& A, ll e) {
    vector<vector<ll>> res(6, vector<ll>(6));
    for (int i = 0; i < 6; i++) res[i][i] = 1;

    while (e > 0) {
        if (e & 1) res = mult(res, A);
        A = mult(A, A);
        e /= 2;
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;

    vector<int> base = {16,8,4,2,1,1};
    vector<vector<ll>> A(6, vector<ll>(6));
    for (int i = 0; i < 6; i++) A[0][i] = 1;
    for (int i = 0; i < 5; i++) A[i+1][i] = 1;

    vector<vector<ll>> A_n = power(A, n);

    ll res = 0;

    for (int i = 0; i < 6; i++) (res += A_n[5][i] * base[i]) %= MOD;

    cout << res << "\n";
}