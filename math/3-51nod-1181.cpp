#include <cstdio>

using namespace std;

int n;
const int N = 1e6+6;
int ptab[N], prim[N], tp;

void init() {
    for (int i = 2; i < N; i++) {
        if (!ptab[i]) prim[++tp] = i;
        for (int j = i+i; j < N; j += i) {
            ptab[j] = 1;
        }
    }
}

int main() {
#ifdef D
    freopen("1181.in", "r", stdin);
#endif
    init();
    scanf("%d", &n);
    for (int i = 1; i <= tp; i++) {
        if (!ptab[i] && prim[i] >= n) {
            printf("%d\n", prim[i]);
            return 0;
        }
    }

    return 0;
}