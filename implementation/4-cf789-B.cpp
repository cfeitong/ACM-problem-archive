#include <algorithm>
#include <algorithm>
#include <cstdio>
#include <cstdio>
#include <cstring>
#include <map>
#include <set>
#include <string>
#include <vector>

typedef long long LL;

LL b, q, l, m;
using namespace std;

const LL N = 2e5;
map<LL, bool> a;
const LL INF = 2e9;

LL abss(LL x) { return x < 0 ? -x : x; }

int main() {
#ifdef D
    freopen("B.in", "r", stdin);
#endif
    scanf("%lld%lld%lld%lld", &b, &q, &l, &m);
    for (LL i = 0; i < m; i++) {
        LL t;
        scanf("%lld", &t);
        a[t] = 1;
    }

    LL ans = 0;
    for (int i = 0; i < 1000000; i++, b *= q) {
        if (abss(b) > l) break;
        if (!a[b]) {
            ans++;
        }
    }

    if (ans > 1e5)
        puts("inf");
    else
        printf("%lld\n", ans);

    return 0;
}