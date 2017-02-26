#include <cstdio>
#include <cassert>
#include <vector>

using namespace std;

const int N = 2e5;
int n, m;
int st[N], vis[N], w[N];
vector<int> key[N];

struct UniFind {
    int pa[2*N];
    UniFind() {for (int i = 0; i < 2*N; i++) pa[i] = i;}
    int find(int k) {
        if (pa[k] == k) return k;
        return pa[k] = find(pa[k]);
    }
    void unite(int a, int b) {
        // printf("%d %d united\n", a, b);
        int p1 = find(a), p2 = find(b);
        pa[p2] = p1;
    }
} uf;


int main() {
#ifdef D
    freopen("d.in", "r", stdin);
#endif
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", w+i);
    }
    for (int i = 1; i <= m; i++) {
        int x; scanf("%d", &x);
        for (int j = 0; j < x; j++) {
            int v; scanf("%d", &v);
            key[v].push_back(i);
        }
    }

    for (int i = 1; i <= n; i++) {
        assert(key[i].size() == 2);
        if (w[i]) {
            uf.unite(key[i][0],   key[i][1]);
            uf.unite(key[i][0]+N, key[i][1]+N);
        } else {
            uf.unite(key[i][0]+N, key[i][1]);
            uf.unite(key[i][0],   key[i][1]+N);
        }
    }

    for (int i = 1; i <= m; i++) {
        if (uf.find(i) == uf.find(i+N)) {
            puts("NO");
            return 0;
        }
    }

    puts("YES");
    return 0;
}
