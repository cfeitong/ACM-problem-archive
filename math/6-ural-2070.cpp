#include <iostream>
using namespace std;

typedef long long LL;
const int N = 2e6 + 5;
LL ptab[N], prim[N], tp;

void init() {
    for (int i = 2; i < N; i++) {
        if (!ptab[i]) prim[tp++] = i;
        for (int j = i; j < N; j += i) {
            ptab[j] = 1;
        }
    }
}

bool isprime(LL v) {
    if (v == 1) return 0;
    for (int i = 0; i < tp && prim[i] * prim[i] <= v; i++) {
        if (v % prim[i] == 0) return 0;
    }
    return 1;
}

LL L, R;

LL calc(LL p) {
    LL cur = p;
    LL ans = 0;
    LL cnt = 2;
    while (cur < L) cur *= p, cnt++;
    while (cur <= R) {
        if (cnt > 2 && isprime(cnt)) ans++;
        cur *= p;
        cnt++;
    }
    return ans;
}

int main() {
#ifdef D
    freopen("i.in", "r", stdin);
#endif
    init();
    while (cin >> L >> R) {
        LL ans = 0;
        for (int i = 0; i < tp; i++) {
            ans += calc(prim[i]);
        }
        cout << R - L + 1 - ans << endl;
    }

    return 0;
}
