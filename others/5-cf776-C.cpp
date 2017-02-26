#include <map>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long LL;

LL labs(LL k) {
    return k < 0 ? -k : k;
}

LL n, k;
vector<LL> vs;
const int N = 1e5+5;
LL arr[N];

int main() {
#ifdef D
    freopen("c.in", "r", stdin);
#endif
    scanf("%lld%lld", &n, &k);
    if (k == 1) vs.push_back(1);
    else if (k == -1) vs.push_back(1),vs.push_back(-1);
    else for (LL t = 1; labs(t) < 1e15; t *= k) {
        vs.push_back(t);
    }
    for (int i = 0; i < n; i++) {
        LL t;
        scanf("%lld", &t);
        if (i) arr[i] = arr[i-1] + t;
        else arr[i] = t;
    }

    map<LL, int> sav;
    sav[0] = 1;
    LL ans = 0;
    for (int i = 0; i < n; i++) {
        for (auto d : vs) {
            LL cur = arr[i]-d;
            if (sav.count(cur)) {
                ans += sav[cur];
            }
        }
        sav[arr[i]]++;
    }
    printf("%lld\n", ans);


    return 0;
}
