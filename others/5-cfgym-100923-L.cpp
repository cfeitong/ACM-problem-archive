#include <cstdio>
#include <cstring>
using namespace std;

typedef long long LL;

const int N = 66;
LL n, k;
char ans[N];

int main() {
#ifdef D
    freopen("l.in", "r", stdin);
#else
    freopen("semipal.in", "r", stdin);
    freopen("semipal.out", "w", stdout);
#endif
    int T;
    for (scanf("%d", &T); T--;) {
        memset(ans, 0, sizeof(ans));
        scanf("%lld%lld", &n, &k);
        if (k > (1LL << (n - 2))) {
            ans[0] = ans[n - 1] = 'b';
            k -= (1LL << (n - 2));
        } else {
            ans[0] = ans[n - 1] = 'a';
        }
        k--;
        for (int i = 0; i < n - 2; i++) {
            if (k & (1LL << i)) {
                ans[n - 2 - i] = 'b';
            } else {
                ans[n - 2 - i] = 'a';
            }
        }
        puts(ans);
    }
    return 0;
}
