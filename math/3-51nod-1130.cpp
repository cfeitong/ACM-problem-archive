#include <cmath>
#include <cstdio>

using namespace std;

int main() {
#ifdef D
    freopen("1130.in", "r", stdin);
#endif
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        long long ans = floor(0.5 * log10(2. * M_PI * n) + n * log10(n / M_E) + 1e-7);
        printf("%lld\n", ans + 1);
    }

    return 0;
}