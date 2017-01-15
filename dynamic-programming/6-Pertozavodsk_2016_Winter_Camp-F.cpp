
#include <functional>
#include <tuple>
#include <cassert>
#include <numeric>
#include <iostream>
#include <bitset>
#include <cctype>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <set>
#include <string>
#include <map>
#include <stack>
#include <cstdio>
#include <cstring>
#include <deque>
#include <sstream>
#include <queue>
#include <climits>
#include <complex>
using namespace std;

#define pb push_back
#define pf push_front
#define mp make_pair
#define mt make_tuple
#define INF 0x3f3f3f3f
#define F first
#define S second
#define speedup ios_base::sync_with_stdio(0);cin.tie(0)
#define all(c) begin(c), end(c)
#define rep(i, j, k) for (int i = (j); i < (int)(k); i++)
#define rep2(i,j, f1,t1, f2,t2) for (int i = (f1); i < (int)(t1); i++) for (int j = (f2); j < (int)(t2); j++)
#define Rep(i, j, k) for (int i = (j); i <= (int)(k); i++)
#define Rep2(i,j, f1,t1, f2,t2) for (int i = (f1); i <= (int)(t1); i++) for (int j = (f2); j <= (int)(t2); j++)
#define per(i, j, k) for (int i = (j); i >= (int)(k); i--)
#define MAXI(a,b) (a)=max((a), (b))
#define MINI(a,b) (a)=min((a), (b))
    typedef long long             LL;
typedef long double           LD;
typedef pair<LL, LL>          PLL;
typedef pair<int, int>        PII;
typedef pair<LD, LD>          PDD;
typedef vector<LD>            VD;
typedef vector<PDD>           VDD;
typedef vector< vector<PDD> > VVD;
typedef vector<LL>            VL;
typedef vector<PLL>           VLL;
typedef vector< vector<PLL> > VVL;
typedef vector<int>           VI;
typedef vector<PII>           VII;
typedef vector<vector<PII> >  VVI;

bool in(LD       &v) {return scanf("%Lf",  &v)!=EOF;}
bool in(LL       &v) {return scanf("%lld", &v)!=EOF;}
bool in(int      &v) {return scanf("%d",   &v)!=EOF;}
bool in(char     *v) {return scanf("%s",    v)!=EOF;}
bool in(char     &v) {return scanf("%c",   &v)!=EOF;}
bool in(unsigned &v) {return scanf("%u",   &v)!=EOF;}
bool in(string   &v) {return (bool)(cin >> v);}
template<typename T, typename... Args> bool in(T &v, Args &...args) {bool ret = in(v); return ret && in(args...);}

void out(LD          v) {printf("%Lf",  v);}
void out(LL          v) {printf("%lld", v);}
void out(int         v) {printf("%d",   v);}
void out(char        v) {printf("%c",    v);}
void out(unsigned    v) {printf("%u",   v);}
void out(string      v) {printf("%s",    v.c_str());}
void out(const char *v) {printf("%s",    v);}
template<typename T> void out(vector<T> &v) {for (int i = 0; i < (int)v.size(); i++) out(v[i]);}
template<typename T, typename ...Args> void out(T v, Args ...args) {out(v); out(args...);}

const int N = 405;
LL dp[N][N];
LL wi[N][N];
LL w;
int ci[N][N];

inline int L(int k) {return 1<<k;}
inline int cnt(int k) {
    int ret = 0;
    while (k) {
        ret += k&1;
        k /= 2;
    }
    return ret;
}

int n, k;
VII ps;
bool ok = 0;

void dfs(int y, int x) {
    if (ok) return;
    if (y == n && x == n) {
        ps.pb({y,x});
        ok = 1;
        return;
    }
    if (dp[y+1][x] == dp[y][x]+wi[y+1][x])
        dfs(y+1, x);
    if (dp[y][x+1] == dp[y][x]+wi[y][x+1])
        dfs(y, x+1);
    if (ok)
        ps.pb({y,x});
}

int main() {
    #ifdef D
    freopen("f.in", "r", stdin);
    #endif
    in(n,k,w);
    Rep(i,1,n) Rep(j,1,n) in(wi[i][j]);
    Rep2(i,j, 1,n, 1,n) {
        int t; in(t);
        ci[i][j] = L(t-1);
    }
    int ans = 0x3f3f3f3f;
    int color = 0;
    for (int cur = 0; cur < L(k); cur++) {
        memset(dp, 0x3f, sizeof(dp));
        dp[0][0] = dp[0][1] = dp[1][0] = 0;
        Rep2(i,j, 1,n, 1,n) {
            if (ci[i][j] & ~cur) continue;
            LL tmp = min(dp[i-1][j], dp[i][j-1]);
            if (tmp <= w) dp[i][j] = min(dp[i][j], tmp+wi[i][j]);
        }
        if (dp[n][n] <= w && ans > cnt(cur)) {
            ans = cnt(cur);
            color = cur;
        }
    }
    if (ans == 0x3f3f3f3f) {
        puts("-1");
        exit(0);
    }
    out(ans, '\n');
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0] = dp[0][1] = dp[1][0] = 0;
    Rep2(i,j, 1,n, 1,n) {
        if (ci[i][j] & ~color) continue;
        LL tmp = min(dp[i-1][j], dp[i][j-1]);
        if (tmp <= w) dp[i][j] = min(dp[i][j], tmp+wi[i][j]);
    }
    dfs(1,1);
    reverse(all(ps));
    for (auto it : ps) {
        out(it.F, ' ', it.S, ' ');
    }
    puts("");
    return 0;
}
