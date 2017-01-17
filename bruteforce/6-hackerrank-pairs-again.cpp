#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <functional>
#include <vector>

using namespace std;

const int N = 3e5 + 5;
vector<int> fac[N];

vector<int> defac(int k) {
    vector<int> ret;
    for (int i = 1; i <= sqrt(k) + 1; i++) {
        if (k % i == 0) {
            ret.push_back(i);
            ret.push_back(k / i);
        }
    }
    sort(begin(ret), end(ret));
    ret.erase(unique(begin(ret), end(ret)), end(ret));
    sort(begin(ret), end(ret), greater<int>());
    return ret;
}

void pre() {
    for (int i = 1; i < N; i++) {
        fac[i] = defac(i);
    }
}

int vis[N];

int main() {
#ifdef D
    freopen("f.in", "r", stdin);
#endif
    int n;
    pre();
    while (scanf("%d", &n) != EOF) {
        memset(vis, 0, sizeof(vis));
        int ans = 0;
        // ax + by = n
        for (int a = 1; a < (n + 1) / 2; a++) {
            for (int x = 1; a * x < n; x++) {
                int by = n - a * x;
                if (by <= a) break;
                for (auto it : fac[by]) {
                    if (it > a && vis[it] != a) {
                        vis[it] = a;
                        ans++;
                    }
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
