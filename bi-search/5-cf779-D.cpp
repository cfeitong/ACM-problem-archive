#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

const int N = 3e5;
char s1[N], s2[N];
int len, len2, del[N];
int use[N];

bool check(int v) {
    fill(begin(use), end(use), 0);
    for (int i = 1; i <= v; i++) use[del[i]] = 1;
    int c = 1, p = 1;
    while (c <= len) {
        if (!use[c] && s1[c] == s2[p]) p++;
        c++;
    }
    return p > len2;
}

int main() {
#ifdef D
    freopen("d.in", "r", stdin);
#endif
    scanf("%s%s", s1+1, s2+1);
    len = strlen(s1+1);
    len2 = strlen(s2+1);
    for (int i = 1; i <= len; i++) scanf("%d", del+i);
    int l = 0, r = len;
    while (l < r) {
        int m = (l+r)/2;
        if (check(m)) {
            l = m+1;
        } else {
            r = m;
        }
    }
    printf("%d\n", l-1);

    return 0;
}
