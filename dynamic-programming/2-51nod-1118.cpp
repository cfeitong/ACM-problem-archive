#include <cstdio>

using namespace std;

typedef long long LL;

const int N = 1e3 + 5;
const LL MOD = 1e9 + 7;

LL dp[N][N];

int main() {
#ifdef D
    freopen("1118.in", "r", stdin);
#endif
    dp[1][1] = 1;
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i + 1][j] += dp[i][j];
            dp[i][j + 1] += dp[i][j];
            dp[i + 1][j] %= MOD;
            dp[i][j + 1] %= MOD;
        }
    }
    printf("%lld\n", dp[n][m]);

    return 0;
}