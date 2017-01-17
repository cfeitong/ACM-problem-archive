#include <cstdio>
#include <vector>
using namespace std;

typedef int I;
typedef long long LL;
#define int LL

int n, m;
int x[20];
LL ans;

LL gcd(LL a, LL b) { return !b ? a : gcd(b, a % b); }
LL lcm(LL a, LL b) { return a / gcd(a, b) * b; }

void dfs(int k, int cnt, LL l) {
    if (k == m) {
        LL val = 0;
        if (cnt) val = 1LL << (cnt - 1);
        if (cnt & 1)
            ans += n / l * val;
        else
            ans -= n / l * val;
        return;
    }
    dfs(k + 1, cnt, l);
    LL nl = lcm(l, x[k]);
    if (nl <= n) dfs(k + 1, cnt + 1, nl);
}

I main() {
#ifdef D
    freopen("g.in", "r", stdin);
#endif

    int T;
    for (scanf("%lld", &T); T; T--) {
        ans = 0;
        scanf("%lld%lld", &n, &m);
        for (int i = 0; i < m; i++) scanf("%lld", x + i);
        dfs(0, 0, 1);
        printf("%lld\n", ans);
    }
    return 0;
}
