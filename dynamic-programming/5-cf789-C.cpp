#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <cstring>


#include <cstdio>
#include <algorithm>

typedef long long LL;

const int N = 2e5;
int n;
LL a[N], v1[N], v2[N], dp[N];

LL abss(LL x) {
    return x < 0 ? -x : x;
}

using namespace std;

int main() {
#ifdef D
    freopen("C.in", "r", stdin);
#endif
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", a+i);
    }
    LL ans = 0;
    for (int i = 1; i < n; i++) {
        v1[i] = -abss(a[i-1]-a[i]);
        if (i&1) v1[i] *= -1;
    }
    for (int i = 1; i <= n; i++) {
        dp[i] = max(v1[i], dp[i-1]+v1[i]);
        ans = max(ans, dp[i]);
    }
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i < n; i++) {
        v2[i] = abss(a[i-1]-a[i]);
        if (i&1) v2[i] *= -1;
    }
    for (int i = 1; i <= n; i++) {
        dp[i] = max(v2[i], dp[i-1]+v2[i]);
        ans = max(ans, dp[i]);
    }

    printf("%lld\n", ans);


    return 0;
}