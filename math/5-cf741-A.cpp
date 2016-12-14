
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

const int N = 102;
int c[N];
int n;
VI loop;
int vis[N];

bool dfs(int k, int cnt) {
    if (vis[k] == 1) {
        loop.pb(cnt);
        return 1;
    }
    else if (vis[k] == 2) {
        return 0;
    }
    else {
        if (!cnt) vis[k] = 1;
        else vis[k] = 2;
        return dfs(c[k], cnt+1);
    }
}

int lcm(int a, int b) {
    return a/__gcd(a,b)*b;
}

void debug() {
    #ifdef D
    for (auto it : loop) {
        out(it, ' ');
    }
    puts("");
    #endif
}

int main() {
#ifdef D
    freopen("a.in", "r", stdin);
#endif
    while (in(n)) {
        loop.clear(); memset(vis, 0, sizeof(vis));
        Rep(i,1,n) in(c[i]);
        bool ccccc = 1;
        Rep(i,1,n) {
            if (!vis[i]) {
                if (!dfs(i, 0)) {
                    puts("-1");
                    ccccc = 0;
                    break;
                }
            }
        }
        if (!ccccc) continue;
        for (auto &it : loop) {
            if (it % 2 == 0) it /= 2;
        }
        int ans = 1;
        for (auto it : loop) {
            ans = lcm(it, ans);
        }
        out(ans, "\n");
        debug();
    }
    return 0;
}
