#include <cstdio>

using namespace std;

int main() {
    freopen("a.in", "r", stdin);
    int a, b;
    while (~scanf("%d%d", &a, &b)) {
        int ans = 0;
        while (a <= b) {
            ans++;
            a *= 3;
            b *= 2;
        }
        printf("%d\n", ans);
    }

    return 0;
}