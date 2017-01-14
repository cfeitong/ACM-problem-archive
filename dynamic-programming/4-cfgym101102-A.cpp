
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

const LL MOD = 1e9+7;
LL n, m, k, w;
#ifdef D
const LL N = 200;
const LL M = 50;
#else
const LL N = 5e4;
const LL M = 200;
#endif
LL cnt1[N][M], cnt2[N][M];
LL a[M], b[M];

int main() {
#ifdef D
    freopen("a.in", "r", stdin);
#endif
    LL T; in(T);
    while (T--) {
        in(n,m,k,w);
        memset(cnt1, 0, sizeof(cnt1));
        memset(cnt2, 0, sizeof(cnt2));
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        Rep(i,1,n) in(a[i]);
        Rep(i,1,m) in(b[i]);
        cnt1[0][0] = cnt2[0][0] = 1;
        Rep(i,1,n) {
            Rep(j,0,w) {
                cnt1[j+a[i]][i] += cnt1[j][i-1];
                cnt1[j+a[i]][i] %= MOD;
                cnt1[j][i] += cnt1[j][i-1];
                cnt1[j][i] %= MOD;
            }
        }
        Rep(i,1,m) {
            Rep(j,0,w) {
                cnt2[j+b[i]][i] += cnt2[j][i-1];
                cnt2[j+b[i]][i] %= MOD;
                cnt2[j][i] += cnt2[j][i-1];
                cnt2[j][i] %= MOD;
            }
        }
        LL ans = 0;
        Rep(i,0,w) {
            LL t1 = i, t2 = w-i;
            if (abs(t1-t2) <= k) {
                ans += (cnt1[t1][n] * cnt2[t2][m]) % MOD;
                ans %= MOD;
            }
        }
        out(ans, '\n');
    }
    return 0;
}
