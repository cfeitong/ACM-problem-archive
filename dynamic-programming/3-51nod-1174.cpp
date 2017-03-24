#include <algorithm>
#include <cmath>
#include <cstdio>

using namespace std;

const int N = 2e4;
int n, q;

struct RMQ {
    int dp[N][30];
    void init(int n) {
        int up = log(n) / log(2);
        for (int j = 1; j <= up; j++) {
            for (int i = 1; i <= n; i++) {
                dp[i][j] =
                    max(dp[i][j - 1], dp[min(i + (1 << (j - 1)), n)][j - 1]);
            }
        }
    }
    int query(int l, int r) {
        int k = log(r - l + 1) / log(2);
        return max(dp[l][k], dp[r - (1 << k) + 1][k]);
    }
} rmq;

int main() {
#ifdef D
    freopen("1174.in", "r", stdin);
#endif
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &rmq.dp[i][0]);
    }
    rmq.init(n);
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        int l, r;
        scanf("%d%d", &l, &r);
        printf("%d\n", rmq.query(l + 1, r + 1));
    }

    return 0;
}