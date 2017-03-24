#include <algorithm>
#include <cstdio>

using namespace std;

const int N = 1e5;

int phi(int n) {
    int ans = n;
    for (int i = 2; i < N; i++) {
        if (n % i == 0) {
            ans = ans / i * (i - 1);
        }
        while (n % i == 0) n /= i;
    }
    if (n != 1) ans = ans / n * (n - 1);
    return ans;
}

int main() {
#ifdef D
    freopen("1136.in", "r", stdin);
#endif
    int n;
    scanf("%d", &n);
    printf("%d\n", phi(n));

    return 0;
}