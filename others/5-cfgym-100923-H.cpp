#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const int N = 2e5;
int b[N];
vector<int> op[N];
int pa[N], cnt[N];
int find(int k) { return k == pa[k] ? k : pa[k] = find(pa[k]); }
void unite(int a, int b) {
    int p1 = find(a), p2 = find(b);
    pa[p2] = p1;
    cnt[p1] += cnt[p2];
}
void dfs(int k, int pa) {
    b[k] *= -1;
    for (int e : op[k]) {
        if (e == pa) continue;
        dfs(e, k);
    }
}
int n, m;

int main() {
#ifdef D
    freopen("h.in", "r", stdin);
#else
    freopen("meciul.in", "r", stdin);
    freopen("meciul.out", "w", stdout);
#endif
    int T;
    for (scanf("%d", &T); T--;) {
        for (int i = 0; i < N; i++) {
            pa[i] = i;
            b[i] = 0;
            cnt[i] = 1;
            op[i].clear();
        }
        scanf("%d%d", &n, &m);
        for (int i = 0; i < m; i++) {
            int x, y, ok = 1;
            scanf("%d%d", &x, &y);
            if (find(x) == find(y)) {
                if (b[x] == b[y]) {
                    ok = 0;
                }
            } else {
                if (!b[x] && !b[y]) {
                    b[x] = 1;
                    b[y] = -1;
                } else if (!b[x]) {
                    b[x] = -b[y];
                } else if (!b[y]) {
                    b[y] = -b[x];
                } else if (b[x] == b[y]) {
                    if (cnt[find(x)] > cnt[find(y)]) {
                        dfs(y, y);
                    } else {
                        dfs(x, x);
                    }
                }
                unite(x, y);
                op[x].push_back(y);
                op[y].push_back(x);
            }
            puts(ok ? "YES" : "NO");
        }
    }
    return 0;
}
