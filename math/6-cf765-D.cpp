#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

const int N = 1e6 + 5;
int f[N], g[N], h[N], q[N], use[N];
int m, n;

int main() {
#ifdef D
    freopen("d.in", "r", stdin);
#endif
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", f + i);
        if (f[i] == i) h[++m] = i, q[i] = m, use[i] = 1;
    };
    for (int i = 1; i <= n; i++) {
        g[i] = q[f[i]];
        if (!use[f[i]]) {
            puts("-1");
            return 0;
        }
    }

    printf("%d\n", m);
    for (int i = 1; i <= n; i++) printf("%d%c", g[i], "\n "[i<n]);
    for (int i = 1; i <= m; i++) printf("%d%c", h[i], "\n "[i<n]);

    return 0;
}
