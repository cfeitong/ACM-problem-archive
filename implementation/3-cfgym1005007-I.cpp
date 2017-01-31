#include <cstdio>
#include <cstring>

using namespace std;

char _n[2000], _s[2000];

int main() {
#ifdef D
    freopen("i.in", "r", stdin);
#endif
    scanf("%s %s", _s, _n);
    char* n = _n;
    char* s = _s;
    int ans = 0;
    while (*n || *s) {
        if (!*n)
            s++;
        else if (!*s)
            n++;
        else if (*s == 'L' && *n != 'L')
            n++;
        else if (*s != 'L' && *n == 'L')
            s++;
        else
            n++, s++;
        ans++;
    }
    printf("%d\n", ans);

    return 0;
}
