#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <cstring>

using namespace std;

const int N = 2e5;
int n, k, a[N];

int main() {
#ifdef D
    freopen("A.in", "r", stdin);
#endif
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += a[i] / k + (a[i] % k != 0);
    }

    printf("%d\n", (ans+1)/2);

    return 0;
}