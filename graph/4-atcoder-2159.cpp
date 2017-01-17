#include <cstdio>
#include <map>
#include <vector>
using namespace std;

const int N = 2e5 + 5;
int pa1[N], pa2[N];
int find(int* p, int v) { return v == p[v] ? v : p[v] = find(p, p[v]); }
void unite(int* p, int a, int b) { p[find(p, b)] = find(p, a); }

typedef long long LL;
int n, k, l;
// vector<int> e1[N], e2[N];

map<LL, int> mp;

int main() {
#ifdef D
    freopen("a.in", "r", stdin);
#endif
    for (int i = 0; i < N; i++) {
        pa1[i] = pa2[i] = i;
    }
    scanf("%d%d%d", &n, &k, &l);
    for (int i = 0; i < k; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        unite(pa1, a, b);
        // e1[a].push_back(b);
        // e1[b].push_back(a);
    }
    for (int i = 0; i < l; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        unite(pa2, a, b);
        // e2[a].push_back(b);
        // e2[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        mp[find(pa1, i) * (LL)(n + 1) + find(pa2, i)] += 1;
    }

    for (int i = 1; i <= n; i++) {
        printf("%d ", mp[find(pa1, i) * (LL)(n + 1) + find(pa2, i)]);
    }
    puts("");

    return 0;
}
