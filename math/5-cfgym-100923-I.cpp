#include <cstdio>

typedef long long LL;

int main() {
#ifdef D
    freopen("i.in", "r", stdin);
#else
    freopen("perechi3.in", "r", stdin);
    freopen("perechi3.out", "w", stdout);
#endif
    LL n;
    int T;
    for (scanf("%d", &T); T--;) {
        scanf("%lld", &n);
        LL nn = n, s = n, e = n;
        LL ans = 0, k = 2;
        while (e * e >= n) {
            s = n / k;
            ans += (k++ - 1) * (e - s);
            e = s;
        }
        for (LL i = 1; i <= e; i++) {
            ans += n / i;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
