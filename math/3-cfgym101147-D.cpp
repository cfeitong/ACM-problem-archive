#include <cstdio>
using namespace std;

typedef long double LD;
typedef long long LL;

int n, m;
LL memo[30][30];

LL C(int n, int m) {
    if (memo[n][m]) return memo[n][m];
    if (n / 2 < m) m = n - m;
    if (m == 0) return 1;
    return memo[n][m] = C(n - 1, m - 1) + C(n - 1, m);
}

int main() {
#ifdef D
    freopen("d.in", "r", stdin);
#else
    freopen("popcorn.in", "r", stdin);
#endif
    int T;
    for (scanf("%d", &T); T--;) {
        scanf("%d%d", &n, &m);
        printf("%lld\n", C(n, m));
    }

    return 0;
}
