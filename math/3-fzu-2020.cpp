#include <iostream>
#include <cmath>
using namespace std;

typedef long long LL;

LL qpowm(LL n, LL m, LL p) {
    if (m == 0) return 1;
    LL ret = qpowm(n, m/2, p) % p;
    ret *= ret;
    ret %= p;
    if (m&1) ret *= n;
    return ret % p;
}

LL inv(LL n, LL p) {
    return qpowm(n, p-2, p);
}

LL C(LL n, LL m, LL p) {
    LL ret = 1;
    for (LL i = 0; i < n; i++) {
        ret *= (m-i)*inv(i+1, p) % p;
        ret %= p;
    }
    return ret;
}

LL lucas(LL n, LL m, LL p) {
    if (!n) return 1;
    return C(n%p, m%p, p) * lucas(n/p, m/p, p) % p;
}

LL n, m, p;

int main() {
    freopen("2020.in", "r", stdin);
    int T; cin >> T;
    while (T--) {
        cin >> n >> m >> p;
        cout << lucas(m, n, p) << endl;
    }

    return 0;
}
