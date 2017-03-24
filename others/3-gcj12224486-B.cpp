#include <cstdio>
#include <algorithm>

using namespace std;

typedef double DB;

const int N = 100;
DB prob[N];

int main() {
    int T; scanf("%d", &T);
    for (int kase = 1; kase <= T; kase++) {
        int n; scanf("%d", &n);
        for (int i = 0; i < 2*n; i++) {
            scanf("%lf", prob+i);
        }
        DB ans = 1;
        sort(prob, prob+2*n);
        for (int i = 0; i < n; i++) {
            ans *= 1 - prob[i] * prob[2*n-i-1];
        }
        printf("Case #%d: %.6f\n", kase, ans);
    }

    return 0;
}
