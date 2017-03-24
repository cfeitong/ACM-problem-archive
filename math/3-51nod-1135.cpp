#include <cstdio>

using namespace std;

typedef long long LL;

const int N = 1e5;
int ptab[N], prim[N], tp;
void init() {
    for (int i = 2; i < N; i++) {
        if (!ptab[i]) {
            prim[tp++] = i;
            for (int j = i + i; j < N; j += i) ptab[j] = 1;
        }
    }
}

LL powm(LL a, LL p, LL m) {
    if (!p) return 1;
    LL ret = powm(a, p / 2, m);
    ret = (ret * ret) % m;
    if (p & 1) ret = (ret * a) % m;
    return ret;
}

bool check(int a, int p) {
    int k = p - 1;
    for (int i = 0; k > 1 && i < tp && prim[i] < p - 1; i++) {
        if (k % prim[i] == 0) {
            if (powm(a, (p - 1) / prim[i], p) == 1) return 0;
        }
        while (k % prim[i] == 0) k /= prim[i];
    }
    if (k != 1 && powm(a, (p - 1) / k, p) == 1) return 0;
    return 1;
}

LL get_prim_root(LL n) {
    for (LL i = 2; 1; i++) {
        if (check(i, n)) return i;
    }
    return -1;
}

int main() {
#ifdef D
    freopen("1135.in", "r", stdin);
#endif
    LL p;
    init();
    scanf("%lld", &p);
    printf("%lld\n", get_prim_root(p));

    return 0;
}