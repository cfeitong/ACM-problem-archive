#include <iostream>
#include <cstdio>

using namespace std;

const int N = 1e5+5;
int ptab[N], prim[N], tp;

void init() {
    for (int i = 2; i < N; i++) {
        if (!ptab[i]) prim[tp++] = i;
        for (int j = i+i; j < N; j += i) {
            ptab[j] = 1;
        }
    }
}

bool isprime(int k) {
    for (int i = 0; i < tp; i++) {
        int p = prim[i];
        if (k % p == 0) return 0;
        if (p * p > k) return 1;
    }
    return 1;
}

int cnt(int k) {
    int ret = 0;
    if (!ptab[k]) return 0;
    for (int i = 0; i < tp; i++) {
        if (k % prim[i] == 0) {
            ret++;
            while (k % prim[i] == 0) k /= prim[i];
        }
        if (k == 1) break;
    }
    return ret;
}

int color;
int ans[N];

int main() {
    int n;
    scanf("%d", &n);
    init();
    for (int i = 2; i <= n+1; i++) {
        if (ptab[i]) ans[i] = 2;
        else ans[i] = 1;
        color = color < ans[i] ? ans[i] : color;
    }

    printf("%d\n", color);
    for (int i = 2; i <= n+1; i++) {
        printf("%d%c", ans[i], "\n "[i < n+1]);
    }


    return 0;
}
