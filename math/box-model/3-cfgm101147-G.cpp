#include <cmath>
#include <iostream>
using namespace std;

typedef long long LL;

const LL MOD = 1e9 + 7;
const int N = 1e3 + 5;

LL S[N][N];

int main() {
#ifdef D
    freopen("g.in", "r", stdin);
#else
    freopen("galactic.in", "r", stdin);
#endif
    int T;

    S[1][1] = 1;
    for (int i = 2; i < N; i++)
        for (int j = 1; j <= i; j++)
            S[i][j] = ((S[i - 1][j - 1]) + j * S[i - 1][j]) % MOD;

    for (scanf("%d", &T); T--;) {
        int n, k;
        scanf("%d%d", &n, &k);
        if (n < k)
            puts("0");
        else {
            LL ans = S[n][k];
            for (int i = 1; i <= k; i++) {
                ans = ans * i % MOD;
            }
            printf("%lld\n", ans);
        }
    }

    return 0;
}
