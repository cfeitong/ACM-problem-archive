#include <algorithm>
#include <cstdio>
#include <cstring>

typedef long long LL;

using namespace std;

LL n;
LL m;
const int N = 1e5 + 5;
int aa[N];
int bb[N];

LL nextl(LL v) {
    LL ret = 1;
    while (ret <= v) {
        ret *= 2;
    }
    return ret / 2;
}

int main() {
#ifdef D
    freopen("k.in", "r", stdin);
#endif
    int* a = aa;
    int* b = bb;
    scanf("%lld%lld", &n, &m);
    m--;
    for (int i = 0; i < n; i++) {
        scanf("%d", a + i);
    }
    while (m) {
        LL l = nextl(m);
        memset(b, 0, sizeof(bb));
        for (int i = 0; i < n; i++) {
            LL idx = ((i + l) % n + n) % n;
            b[i] = a[i] ^ a[idx];
        }
        swap(a, b);
        m -= l;
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    puts("");
    return 0;
}
