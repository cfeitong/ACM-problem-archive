
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

int n;
const int N = 1e5+5;
LL a[N],b[N],c[N];
map<PLL,VLL> sp;

#define MAXI(a,b) (a) = max((a), (b))
#define MINI(a,b) (a) = min((a), (b))

int main() {
    // freopen("d.in", "r", stdin);
    in(n);
    rep(i,0,n) {
        in(a[i],b[i],c[i]);
        LL t[] = {a[i],b[i],c[i]};
        LL sum = a[i]+b[i]+c[i];
        sort(t,t+3);
        rep2(k,j, 0,3, k+1,3) {
            sp[{t[k],t[j]}].pb({sum-t[k]-t[j], i});
        }
    }

    LL ans = 0;
    LL s1=-1, s2=-1;
    for (auto &it : sp) {
        vector<PLL> tt;
        set<LL> vis;
        for (auto it1 : it.S) {
            if (vis.find(it1.S) == vis.end()) {
                tt.pb(it1);
                vis.insert(it1.S);
            }
        }
        it.S = tt;
        sort(all(it.S), [](pair<LL,LL> a, pair<LL,LL> b) {return a.F > b.F;});
        LL cur = min(it.F.F, it.F.S);
        LL ts1=-1, ts2=-1;
        if (it.S.size() >= 2) {
            MINI(cur, it.S[0].F+it.S[1].F);
            ts1 = it.S[0].S; ts2 = it.S[1].S;
        }
        else {
            MINI(cur, it.S[0].F);
            ts1 = it.S[0].S; ts2 = -1;
        }
        if (cur > ans) {
            s1 = ts1; s2 = ts2;
            ans = cur;
        }
    }

    if (s2 < 0) {
        out(1,'\n');
        out(s1+1,'\n');
    }
    else {
        out(2,'\n');
        out(s1+1,' ',s2+1,'\n');
    }

    return 0;
}
