#include <algorithm>
#include <cstdio>

using namespace std;
typedef long long LL;
typedef int I;

LL n, m, x, y;
LL k;
LL g[200][200];

I main() {
#ifdef D
    freopen("c.in", "r", stdin);
#endif
    scanf("%lld%lld%lld%lld%lld", &n, &m, &k, &x, &y);
    if (n == 1) {
        LL tot = k / m;
        k %= m;
        for (LL i = 0; i < m; i++) {
            g[0][i] += tot;
            if (k) {
                k--;
                g[0][i]++;
            }
        }
        LL mi = 1e18 + 1, mx = 0;
        for (LL i = 0; i < n; i++) {
            for (LL j = 0; j < m; j++) {
                mi = min(mi, g[i][j]);
                mx = max(mx, g[i][j]);
            }
        }

        printf("%lld %lld %lld\n", mx, mi, g[x - 1][y - 1]);
        return 0;
    }
    LL tot = k / ((2 * n - 2) * m);
    k %= (2 * n - 2) * m;
    for (LL i = 0; i < n; i++) {
        for (LL j = 0; j < m; j++) {
            if (k) {
                k--;
                g[i][j]++;
            }
        }
    }
    for (LL i = n - 2; i >= 1; i--) {
        for (LL j = 0; j < m; j++) {
            if (k) {
                k--;
                g[i][j]++;
            }
        }
    }

    for (LL i = 0; i < n; i++) {
        for (LL j = 0; j < m; j++) {
            if (i == 0 || i == n - 1) {
                g[i][j] += tot;
            } else {
                g[i][j] += 2 * tot;
            }
        }
    }

    LL mi = 1e18 + 1, mx = 0;
    for (LL i = 0; i < n; i++) {
        for (LL j = 0; j < m; j++) {
            mi = min(mi, g[i][j]);
            mx = max(mx, g[i][j]);
        }
    }

    printf("%lld %lld %lld\n", mx, mi, g[x - 1][y - 1]);
    return 0;
}
