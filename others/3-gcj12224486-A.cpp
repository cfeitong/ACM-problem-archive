#include <cstdio>
#include <set>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 200;
int cnt[N];

int main() {
#ifdef D
    freopen("a.in", "r", stdin);
#endif
    int T; scanf("%d", &T);
    for (int kase = 1; kase <= T; kase++) {
        set<pair<int,int>> used;
        memset(cnt, 0, sizeof(cnt));
        int f, s; scanf("%d%d", &f, &s);
        for (int i = 0; i < f; i++) {
            int a, b; scanf("%d%d", &a, &b);
            if (used.count({a,b})) continue;
            used.insert({a,b});
            if (a != b) {
                cnt[a]++; cnt[b]++;
            } else {
                cnt[a]++;
            }
        }
        int ans = *max_element(begin(cnt), end(cnt));
        printf("Case #%d: %d\n", kase, ans);
    }

    return 0;
}
