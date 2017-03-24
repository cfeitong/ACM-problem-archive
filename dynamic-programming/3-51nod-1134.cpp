#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 3e5;

int n;
int a[N];
int dp[N];
int ans;

int main() {
#ifdef D
    freopen("1134.in", "r", stdin);
#endif
    scanf("%d", &n);
    for (int i = 0; i < N; i++) dp[i] = 1e9+1;
    for (int i = 0; i < n; i++) {
        int t; scanf("%d", &t);
        auto iter = lower_bound(dp, dp+ans, t);
        *iter = min(*iter, t);
        if (iter - dp == ans) ans++;
    }
    printf("%d\n", ans);
}