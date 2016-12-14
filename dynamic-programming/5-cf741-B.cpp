
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

#define MAXI(a,b) a = max((a),(b))

const int N = 1e3+5;
int n, m, w;
int wi[N], b[N];
int pa[N];

struct G {
    VI meb;
    int b, w, id;
    bool has(int k) {
        auto it = lower_bound(all(meb), k);
        if (it == meb.end() || *it != k) return 0;
        return 1;
    }
};

vector<G> gps;
int vis[N];
bool used[N];

int dp[N];
int ndp[N];

// dsu
int find(int k) {return k==pa[k]?k:pa[k]=find(pa[k]);}
void unite(int a, int b) {pa[find(b)]=pa[find(a)];}

int main() {
    #ifdef D
    freopen("b.in", "r", stdin);
    #endif
    memset(vis, -1, sizeof(vis));
    in(n,m,w);
    rep(i,0,n) in(wi[i]);
    rep(i,0,n) in(b[i]);
    rep(i,0,N) pa[i] = i;
    rep(i,0,m) {
        int a,b; in(a,b);
        unite(a-1,b-1);
    }

    rep(i,0,n) {
        int id = find(i);
        if (vis[id] < 0) {
            gps.pb({VI(),0,0,id});
            vis[id] = gps.size()-1;
        }
    }

    rep(i,0,n) {
        auto &g = gps[vis[find(i)]];
        g.b += b[i];
        g.w += wi[i];
        g.meb.pb(i);
    }

    for (auto &g : gps) sort(all(g.meb));
    for (auto &g : gps) {
        copy(begin(dp), end(dp), begin(ndp));
        for (int tw = 0; tw <= w; tw++) {
            if (tw+g.w <= w) {
                MAXI(ndp[tw+g.w], dp[tw]+g.b);
            }
            for (auto u : g.meb) {
                if (tw+wi[u] <= w) {
                    MAXI(ndp[tw+wi[u]], dp[tw]+b[u]);
                }
            }
        }
        copy(begin(ndp), end(ndp), begin(dp));
    }
    int ans = *max_element(begin(dp), end(dp));
    out(ans, '\n');
    return 0;
}
