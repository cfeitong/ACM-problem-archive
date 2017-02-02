#include <algorithm>
#include <cstdio>

using namespace std;

const int N = 1e5 + 5;
int col[N], row[N];
int n, m;

int main() {
#ifdef D
    freopen("h.in", "r", stdin);
#endif
    while (~scanf("%d%d", &n, &m)) {
        for (int i = 0; i < n; i++) scanf("%d", col + i);
        for (int i = 0; i < m; i++) scanf("%d", row + i);
        int ans1 = -1, ans2 = ans1;
        ans1 = max(ans1, min(col[0], row[m - 1]));
        ans1 = max(ans1, min(col[n - 1], row[0]));
        for (int i = 1; i < n - 1; i++)
            ans1 = max(ans1, min(row[0], min(row[m - 1], col[i])));

        ans2 = max(ans2, min(row[0], col[n - 1]));
        ans2 = max(ans2, min(row[m - 1], col[0]));
        for (int i = 1; i < m - 1; i++)
            ans2 = max(ans2, min(col[0], min(col[n - 1], row[i])));

        int ans = max(ans1, ans2);
        printf("%d\n", ans);
    }

    return 0;
}
