#include <cstdio>
#include <set>
#include <vector>

using namespace std;

const int N = 2e5;
vector<int> g[N];

long long n, m;
long long cnt;

bool vis[N];

void dfs(int k) {
    if (!vis[k]) {
        vis[k] = 1;
        cnt++;
       for (auto it : g[k]) {
           dfs(it);
       }
    }
}

int main() {
    freopen("B.in", "r", stdin);
    scanf("%lld%lld", &n, &m);
    for (int i = 0; i < m; i++) {
        int a,b; scanf("%d%d", &a, &b);
        g[a].push_back(b); g[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        cnt = 0;
        dfs(i);
        m -= cnt * (cnt-1) / 2;
    }
    puts(!m ? "YES" : "NO");

    return 0;
}