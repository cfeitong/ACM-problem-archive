#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdio>
#include <cstring>
#include <map>
#include <set>
#include <string>
#include <vector>

typedef long long LL;

using namespace std;

const LL N = 2e6;

int n, m;
LL self;
vector<int> g[N];

struct UniFind {
    int pa[N];
    void init() {
        for (int i = 0; i < N; i++) pa[i] = i;
    }
    UniFind() {init();}
    void unite(int a, int b) {
        pa[find(b)] = find(a);
    }
    int find(int k) {
        return k == pa[k] ? k : pa[k] = find(pa[k]);
    }
} uf;

int main() {
#ifdef D
    freopen("D.in", "r", stdin);
#endif
    scanf("%d%d", &n, &m);
    vector<int> s;
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        s.push_back(u);
        s.push_back(v);
        if (u == v) {
            self++;
        } else {
            g[u].push_back(v);
            g[v].push_back(u);
            uf.unite(u, v);
        }
    }

    LL ans = self * (self - 1) / 2 + self * (m - self);
    for (int i = 1; i <= n; i++) {
        LL sz = g[i].size();
        ans += sz * (sz - 1) / 2;
    }

    sort(begin(s), end(s));
    s.erase(unique(begin(s), end(s)), end(s));

    for (auto it : s) {
        if (uf.find(s.back()) != uf.find(it)) ans = 0;
    }

    printf("%lld\n", ans);

    return 0;
}