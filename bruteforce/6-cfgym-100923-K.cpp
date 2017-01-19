#include <cassert>
#include <cstdio>
#include <vector>
using namespace std;

typedef int I;
typedef long long LL;
#define int LL

int n, a, b;
int x1, q, q1;
int MOD = 1e7 + 3;

int pos[100005];

I main() {
#ifdef D
    freopen("k.in", "r", stdin);
#else
    freopen("pocnitoare.in", "r", stdin);
    freopen("pocnitoare.out", "w", stdout);
#endif
    scanf("%lld%lld%lld", &n, &a, &b);
    scanf("%lld%lld%lld", &x1, &q, &q1);
    int t = x1;
    for (int i = 2; i < MOD; i++) {
        t = ((i - 1) * t + a) % n;
        if (i % 100 == 0) {
            pos[i / 100] = t;
        }
    }

    t = q1;
    for (int i = 1; i <= q; i++) {
        int aa, s;
        if (t < 100) {
            s = 1;
            aa = x1;
        } else {
            aa = pos[t / 100];
            s = t / 100 * 100;
        }
        for (int y = s + 1; y <= t; y++) {
            aa = ((y - 1) * aa + a) % n;
        }
        printf("%lld\n", aa);
        t = (i * aa + b) % MOD + 1;
    }
    return 0;
}
