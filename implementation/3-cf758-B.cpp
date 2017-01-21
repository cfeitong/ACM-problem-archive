#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

char s[200];
vector<char> c{'R', 'B', 'Y', 'G'};
int cnt[256];
bool use[256];

int main() {
#ifdef D
    freopen("b.in", "r", stdin);
#endif
    scanf("%s", s);
    int l = strlen(s);
    bool ok = 0;
    sort(begin(c), end(c));
    do {
        memset(cnt, 0, sizeof(cnt));
        memset(use, 0, sizeof(use));
        ok = 1;
        for (int i = 0; i < l; i++) {
            if (s[i] == '!') {
                cnt[c[i % 4]]++;
            } else if (s[i] == c[i % 4]) {
                use[s[i]] = 1;
            } else {
                ok = 0;
                break;
            }
        }
        ok &= use['R'] && use['B'] && use['Y'] && use['G'];
        if (ok) {
            break;
        }
        // printf("%c%c%c%c\n", c[0], c[1], c[2], c[3]);
    } while (next_permutation(begin(c), end(c)));

    printf("%d %d %d %d\n", cnt['R'], cnt['B'], cnt['Y'], cnt['G']);

    return 0;
}
