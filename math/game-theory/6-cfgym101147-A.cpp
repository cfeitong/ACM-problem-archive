#include <cstdio>
#include <cstring>

using namespace std;

int main() {
#ifdef D
    freopen("a.in", "r", stdin);
#else
    freopen("powers.in", "r", stdin);
#endif
    // int t;
    // scanf("%d", &t);
    // memset(check, 0, sizeof(check));
    // for (int i = 0; i < t; i++) {
    //     check[i] = i & 1;
    // }
    // check[t] = 1;
    // for (int i = t + 1; i < 100; i++) {
    //     for (int tt = 1; i - tt >= 0; tt *= t) {
    //         if (!check[i - tt]) {
    //             check[i] = 1;
    //             break;
    //         }
    //     }
    // }
    // for (int i = 0; i < 100; i++) {
    //     printf("%d: %d\n", i, check[i]);
    // }
    int T;
    for (scanf("%d", &T); T--;) {
        int k;
        scanf("%d", &k);
        int ans[200];
        for (int i = 0; i < k; i++) {
            int b, n;
            scanf("%d%d", &b, &n);
            if (b & 1) {
                ans[i] = n & 1;
            } else {
                if (n < b)
                    ans[i] = n & 1;
                else {
                    n %= b + 1;
                    if (n == b) {
                        ans[i] = 2;
                    } else {
                        ans[i] = (n & 1);
                    }
                }
            }
        }
        int t = 0;
        for (int i = 0; i < k; i++) {
            t ^= ans[i];
        }
        printf("%d\n", t ? 1 : 2);
    }

    return 0;
}
