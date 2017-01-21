#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const int N = 1e3;
int a[N];

int main() {
#ifdef D
    freopen("a.in", "r", stdin);
#endif
    int n;
    int mx = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        mx = max(mx, a[i]);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += mx - a[i];
    }
    printf("%d\n", ans);

    return 0;
}
