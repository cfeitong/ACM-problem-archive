#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

typedef long long LL;
typedef long double LD;

LL cvt(char* st, char* ed) {
    char tmp = *ed;
    *ed = 0;
    LL ret = atoll(st);
    *ed = tmp;
    return ret;
}

char s[100];
LL n;
LL dp[100];
int l;

int main() {
#ifdef D
    freopen("d.in", "r", stdin);
#endif
    while (scanf("%lld %s", &n, s + 1) != EOF) {
        l = strlen(s + 1) + 1;
        for (int i = 0; i < 100; i++) dp[i] = 1e18 + 1;
        dp[0] = 0;
        for (int i = 1; i < l; i++) {
            LL val;
            for (int j = 0; i + j < l && (val = cvt(s + i, s + i + j + 1)) < n;
                 j++) {
                dp[i + j] = min(dp[i + j] * 1.0L, dp[i - 1] * (LD)n + val);
                if (val == 0) break;
            }
        }
        printf("%lld\n", dp[l - 1]);
        // for (int i = 0; i < 100; i++) printf("%lld ", dp[i]);
        // puts("");
        // break;
    }

    return 0;
}
