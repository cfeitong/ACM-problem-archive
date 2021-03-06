
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
#define all(c) c.begin(), c.end()
#define rep(i, j, k) for (int i = (j); i < (int)(k); i++)
#define rep2(i,j, f1,t1, f2,t2) for (int i = (f1); i < (int)(t1); i++) for (int j = (f2); j < (int)(t2); j++)
#define Rep(i, j, k) for (int i = (j); i <= (int)(k); i++)
#define Rep2(i,j, f1,t1, f2,t2) for (int i = (f1); i <= (int)(t1); i++) for (int j = (f2); j <= (int)(t2); j++)
#define per(i, j, k) for (int i = (j); i >= (int)(k); i--)
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

const int N = 40200;
const int MOD = 1000000007;

VI son[N];
int pa[N];
int n, m;

LL fact[N];
int cnt[N];
LL ans[N];
map<LL, LL> inv;
LL exgcd(LL a, LL b, LL &x, LL &y) {
    if (!b) {
        x = 1; y = 0;
        return a;
    }
    LL tx, ty;
    LL ret = exgcd(b, a%b, tx, ty);
    x = ty;
    y = tx-a/b*ty;
    return ret;
}

LL get_inv(LL k) {
    LL x, y;
    exgcd(k, MOD, x, y);
    return (x % MOD + MOD) % MOD;
}


void pre() {
    inv[1] = fact[0] = fact[1] = 1;
    rep(i,2,N) {
        fact[i] = fact[i-1] * i % MOD;
        inv[fact[i]] = get_inv(fact[i]);
    }
}

LL C(LL n, LL m) {
    if (m >= n/2+1) m = n-m;
    LL t1 = inv[fact[m]], t2 = inv[fact[n-m]];
    return fact[n] * inv[fact[m]] % MOD * inv[fact[n-m]] % MOD;
}

int dfs(int k) {
    int ret = 1;
    for (auto it : son[k]) {
        ret += dfs(it);
    }
    int rest = ret - 1;
    for (auto it : son[k]) {
        ans[k] *= C(rest, cnt[it]) * ans[it] % MOD;
        ans[k] %= MOD;
        rest -= cnt[it];
    }
    return cnt[k] = ret;
}

int main() {
#ifdef D
    freopen("11174.in", "r", stdin);
#endif
    pre();
    int T; in(T);
    while (T--) {
        in(n, m);
        rep(i,0,n+10) {
            cnt[i] = pa[i] = 0;
            ans[i] = 1;
            son[i].clear();
        }
        rep(i,0,m) {
            int a, b; in(a,b);
            pa[a] = b;
            son[b].pb(a);
        }
        Rep(i,1,n) {
            if (!pa[i]) son[0].pb(i);
        }
        dfs(0);
        out(ans[0], '\n');
    }
    return 0;
}
