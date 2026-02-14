#include "bits/stdc++.h"
using namespace std;

long long query(long long k) {
    if (k < 10) return k;

    long long before = 0;

    long long digitsBefore = 0, numDigits = 1, power = 1;

    while (digitsBefore + numDigits * 9 * power < k) {
        before += 9 * power;
        digitsBefore += numDigits * 9 * power;
        numDigits++;
        power *= 10;
    }

    long long digitsD = k - digitsBefore;
    long long numD = (digitsD - 1) / numDigits;
    long long num = before + 1 + numD;

    long long pos = numDigits - ((digitsD - 1) % numDigits);

    long long isolatePower = 1;

    for (int i = 1; i < pos; i++) isolatePower *= 10;

    return (num / isolatePower) % 10;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;

    for (long i = 0; i < q; i++) {
        long long k;
        cin >> k;

        cout << query(k) << "\n";
    }
}