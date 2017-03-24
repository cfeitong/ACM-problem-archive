#include <algorithm>
#include <cmath>
#include <cstdio>

using namespace std;

int main() {
#ifdef D
    freopen("1072.in", "r", stdin);
#endif
    int T;
    for (scanf("%d", &T); T--;) {
        int a, b;
        scanf("%d%d", &a, &b);
        if (a > b) swap(a, b);
        int t = (sqrt(5.0) + 1) / 2 * (b - a);
        puts(t != a ? "A" : "B");
    }

    return 0;
}