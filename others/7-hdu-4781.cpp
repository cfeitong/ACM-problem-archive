#include <cstdio>
#include <vector>
#include <cassert>
#include <cstring>

using namespace std;

const int N = 100;

int n, m;
int g[N][N];
int pre[N];
bool use[N*N];
int sum;
pair<int,int> ans[N*N];

bool add(int k) {
    if (use[k]) return 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j || g[i][j] || g[j][i]) continue;
            if (i < j) {
                if ((pre[j] - pre[i]) % 3 == k % 3) {
                    // printf("add %d to %d (%d)\n", i, j, k);
                    g[i][j] = k;
                    return 1;
                }
            } else if (i > j) {
                if ((sum - (pre[j]-pre[i])) % 3 == k % 3) {
                    // printf("add %d to %d (%d)\n", j, i, k);
                    g[j][i] = k;
                    return 1;
                }
            }
        }
    }
    return 0;
}

int main() {
#ifdef D
    freopen("a.in", "r", stdin);
#endif
    int T; scanf("%d", &T);
    for (int kase = 1; kase <= T; kase++) {
        memset(g, 0, sizeof(g));
        memset(pre, 0, sizeof(pre));
        memset(use, 0, sizeof(use));
        scanf("%d%d", &n, &m);
        sum = 0;
        for (int i = 0; i < n-1; i++) {
            sum += g[i][i+1] = i+1;
            pre[i+1] = sum;
            use[i+1] = 1;
        }
        if ((sum+n) % 3 == 0) {
            g[n-1][0] = n;
            sum += n;
            use[n] = 1;
        } else if ((sum+n+1) % 3 == 0) {
            g[n-1][0] = n+1;
            sum += n+1;
            use[n+1] = 1;
        } else if ((sum+n+2) % 3 == 0) {
            g[n-1][0] = n+2;
            sum += n+2;
            use[n+2] = 1;
        } else {
            assert(0);
        }

        bool ok = 1;
        for (int j = n; j <= m; j++) {
            if (!add(j)) {
                ok = 0; break;
            }
        }


        printf("Case #%d:\n", kase);
        if (!ok) puts("-1");
        else {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (g[i][j]) {
                        ans[g[i][j]] = make_pair(i+1, j+1);
                        // printf("%d %d %d\n", i+1, j+1, g[i][j]);
                    }
                }
            }
            for (int i = 1; i <= m; i++) {
                printf("%d %d %d\n", ans[i].first, ans[i].second, i);
            }
        }
    }

    return 0;
}
