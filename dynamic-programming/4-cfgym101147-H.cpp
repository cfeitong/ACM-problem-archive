#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>

using namespace std;

int g[20][20][20];
int dp[20][20][20];

int main() {
#ifdef D
    freopen("h.in", "r", stdin);
#else
    freopen("commandos.in", "r", stdin);
#endif
    int T;
    for (scanf("%d", &T); T--;) {
        memset(g, 0, sizeof(g));
        memset(dp, 0, sizeof(dp));
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            int f, y, x, h;
            scanf("%d%d%d%d", &f, &y, &x, &h);
            g[f][y][x] = h;
        }

        for (int f = 10; f; f--) {
            for (int y = 1; y <= 10; y++) {
                for (int x = 1; x <= 10; x++) {
                    int cur = g[f][y][x];
                    dp[f][y][x] = max(dp[f][y][x], cur + dp[f][y][x - 1]);
                    dp[f][y][x] = max(dp[f][y][x], cur + dp[f][y - 1][x]);
                    dp[f][y][x] = max(dp[f][y][x], cur + dp[f + 1][y][x]);
                }
            }
        }

        printf("%d\n", dp[1][10][10]);
    }

    return 0;
}
