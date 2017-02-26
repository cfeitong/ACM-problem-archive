#include <queue>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;
const int N = 2e5+5;
int a[N], b[N];
int n, k;
bool use[N];

int main() {
    // freopen("c.in", "r", stdin);
    scanf("%d%d", &n, &k);
    for (int i = 0;  i < n; i++) scanf("%d", a+i);
    for (int i = 0;  i < n; i++) scanf("%d", b+i);
    vector<int> vs;
    for (int i = 0;  i < n; i++) vs.push_back(i);
    int ans = 0;
    sort(begin(vs), end(vs), [&](int v1, int v2) {return a[v1]-b[v1] < a[v2]-b[v2];});
    for (int i = 0; i < n; i++) {
        if (i < k || a[vs[i]]-b[vs[i]] < 0) ans += a[vs[i]];
        else ans += b[vs[i]];
    }
    printf("%d\n", ans);
    return 0;
}

