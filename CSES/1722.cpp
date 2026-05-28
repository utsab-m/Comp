#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using ull = unsigned long long;

const int MOD = 1e9+7;

vector<vector<ll>> mult(vector<vector<ll>>& A, vector<vector<ll>>& B) {
    vector<vector<ll>> C(2, vector<ll>(2));

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                (C[i][j] += A[i][k] * B[k][j]) %= MOD;
            }
        }
    }

    return C;
}

vector<vector<ll>> power(vector<vector<ll>>& A, ll n) {
    vector<vector<ll>> res = {{1, 0}, {0, 1}};
    
    while (n > 0) {
        if (n & 1) res = mult(res, A);
        A = mult(A, A);
        n >>= 1;
    }

    return res;
}

ull get_fib(vector<vector<ll>>& f, ll n) {
    vector<vector<ll>> mat = power(f, n);
    return mat[1][0];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ull n;
    cin >> n;

    vector<vector<ll>> fib = {{1, 1}, {1, 0}};

    cout << get_fib(fib, n) << "\n";
}