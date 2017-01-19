#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>
#include <queue>
#include <tuple>
#include <vector>
using namespace std;

#define F first
#define S second

int n, m;
typedef long long LL;

struct E {
    int f, t;
    LL c;
    bool operator<(const E& o) const {
        if (f == o.f) {
            if (t == o.t) {
                return c < o.c;
            }
            return t < o.t;
        }
        return f < o.f;
    }
};

const int N = 2e5 + 5;

map<E, int> idx;
vector<pair<int, LL>> edg[N];
vector<int> ans;
LL d[N];
bool vis[N];

void dij() {
    typedef pair<LL, int> T;
    priority_queue<T, vector<T>, greater<T>> q;
    q.push({0, 1});
    while (!q.empty()) {
        auto cur = q.top();
        q.pop();
        for (auto e : edg[cur.S]) {
            int to = e.S;
            LL v = e.F + cur.F;
            if (v < d[to]) {
                d[to] = v;
                q.push({v, to});
            }
        }
    }
}

void dfs(int k) {
    for (auto e : edg[k]) {
        int to = e.S;
        LL v = e.F + d[k];
        if (d[to] == v) {
            int id = idx[{k, to, e.F}];
            ans.push_back(id);
            dfs(to);
        }
    }
}

int main() {
#ifdef D
    freopen("b.in", "r", stdin);
#else
    freopen("algoritm.in", "r", stdin);
    freopen("algoritm.out", "w", stdout);
#endif
    int T;
    for (scanf("%d", &T); T--;) {
        for (int i = 0; i < N; i++) {
            d[i] = 0x3f3f3f3f3f3f3f3fLL;
            edg[i].clear();
            vis[i] = 0;
        }
        d[1] = 0;
        idx.clear();
        ans.clear();
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= m; i++) {
            int f, t, c;
            scanf("%d%d%d", &f, &t, &c);
            idx[E{f, t, c}] = i;
            edg[f].push_back({c, t});
        }
        dij();
        dfs(1);
        for (auto it : ans) {
            printf("%d ", it);
            vis[it] = 1;
        }
        for (int i = 1; i <= m; i++) {
            if (!vis[i]) {
                printf("%d ", i);
            }
        }
        puts("");
    }

    return 0;
}
