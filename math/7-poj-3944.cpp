#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long LL;

LL n, k, p;

LL ptab[10300], prim[2000], tp;
LL fac[2000][10300];

void init_prim() {
    for (int i = 2; i < 10300; i++) {
        if (!ptab[i]) {
            prim[tp++] = i;
            for (int j = i+i; j < 10300; j += i) {
                ptab[j] = 1;
            }

            fac[tp-1][0] = 1;
            for (int j = 1; j < i; j++) {
                fac[tp-1][j] = j*fac[tp-1][j-1] % i;
            }
        }
    }
}

LL qpowm(int n, int p, int mod) {
    if (!p) return 1;
    LL ret = qpowm(n, p/2, mod);
    ret *= ret;
    ret %= mod;
    if (p&1) ret *= n;
    return ret % mod;
}

LL inv(int k, int mod) {
    return qpowm(k, mod-2, mod);
}

LL C(int n, int m, int mod) {
    if (m > n) return 0;
    if (m == 0 || n == m) return 1;
    int idx = lower_bound(prim, prim+tp, mod) - prim;
    LL a = fac[idx][n], b = fac[idx][n-m] * fac[idx][m] % mod;
    return a * inv(b, mod) % mod;
}

LL lucas(int n, int m, int mod) {
    if (!m) return 1;
    return C(n%mod, m%mod, mod) * lucas(n/mod, m/mod, mod) % mod;
}

int main() {
    freopen("3944.in", "r", stdin);

    init_prim();

    int kase = 1;
    while (scanf("%lld%lld%lld", &n, &k, &p) != EOF) {
        k = min(k, n-k);
        printf("Case #%d: %lld\n", kase++, (n-k+lucas(n+1, k, p)) % p);
    }

    return 0;
}
