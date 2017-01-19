#include <cstdio>

using namespace std;

typedef long long LL;
const LL MOD = 1e9 + 7;
// const int N = 1e6 + 6;
// LL a[N];
int n;

int main() {
#ifdef D
    freopen("a.in", "r", stdin);
#else
    freopen("azerah.in", "r", stdin);
    freopen("azerah.out", "w", stdout);
#endif
    int T;
    for (scanf("%d", &T); T--;) {
        scanf("%d", &n);
        LL odd = 0, even = 0;
        for (int i = 0; i < n; i++) {
            LL t, nodd, neven;
            scanf("%lld", &t);
            if (t & 1) {
                nodd = odd + even + 1;
                neven = odd + even;
            } else {
                nodd = odd * 2;
                neven = even * 2 + 1;
            }
            odd = nodd % MOD;
            even = neven % MOD;
        }
        printf("%lld\n", even);
    }

    return 0;
}
