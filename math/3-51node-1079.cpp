#include <cstdio>

using namespace std;

const int N = 20;
int p[N], m[N], n;

typedef long long LL;

void exgcd(LL a, LL b, LL& x, LL& y) {
    if (!b) x = 1, y = 0;
    else exgcd(b, a%b, y, x), y -= a/b*x;
}

LL inv(LL k, LL m) {
    LL x, y;
    exgcd(k, m, x, y);
    return (x % m + m) % m;
}

LL CRT() {
    LL M = 1, ans = 0;
    for (int i = 0; i < n; i++) M *= p[i];
    for (int i = 0; i < n; i++) ans += M / p[i] * inv(M / p[i], p[i]) * m[i] % M, ans %= M;
    return (ans + M) % M;
}

int main() {
#ifdef D
    freopen("1079.in", "r", stdin);
#endif
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", p + i, m + i);
    }
    printf("%lld\n", CRT());

    return 0;
}