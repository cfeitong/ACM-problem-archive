#include <algorithm>
#include <cstdio>

using namespace std;

typedef long long LL;

int n, a, b;
LL dpa[400];
LL dpb[400];
const LL MOD = 1e9 + 7;

int main() {
#ifdef D
    freopen("g.in", "r", stdin);
#endif
    scanf("%d%d%d", &n, &a, &b);
    dpa[0] = dpb[0] = 1;
    for (int i = 1; i <= n; i++) {
        LL acca = 0, accb = 0;
        for (int j = a; j >= 1; j--) {
            dpa[j] = dpa[j - 1];
            dpa[j] %= MOD;

            acca += dpa[j];
            acca %= MOD;
        }
        for (int j = b; j >= 1; j--) {
            dpb[j] = dpb[j - 1];
            dpb[j] %= MOD;

            accb += dpb[j];
            accb %= MOD;
        }

        dpb[0] = acca;
        dpa[0] = accb;
    }

    LL ans = dpb[0] + dpa[0];
    printf("%lld\n", ans % MOD);

    return 0;
}
