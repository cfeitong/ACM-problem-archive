#include <cstdio>
#include <cstring>
using namespace std;

int abs(int a) {
    return a < 0 ? -a : a;
}

int n;
int a[200], b[200];

int main() {
    while (~scanf("%d",&n)) {
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    for (int i = 0; i < n; i++) {
        int t;
        scanf("%d", &t);
        a[t]++;
    }
    for (int i = 0; i < n; i++) {
        int t;
        scanf("%d", &t);
        b[t]++;
    }
    int ans = 0, acc = 0;
    for (int i = 1; i <= 5; i++) {
        acc += a[i]-b[i];
        ans += abs(a[i]-b[i]);
    }
    for (int i = 1; i <= 5; i++) {
        if ((a[i]+b[i]) & 1) acc = 1;
    }
    if (acc) puts("-1");
    else printf("%d\n", ans/4);
    }

    return 0;
}
