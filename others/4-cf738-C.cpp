
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
template<typename T> void out(vector<T> &v) {for (int i = 0; i < (int)v.size(); i++) out(v[i], ' ');}
template<typename T, typename ...Args> void out(T v, Args ...args) {out(v); out(args...);}

int ncar, nst, len, t;
const int N = 3e5;
int price[N], cap[N];
int gas[N];

bool ok(int ca, int ti) {
    double t = 0;
    Rep(i,0,nst) {
        int dis = gas[i+1]-gas[i];
        if (dis*2 <= ca) {
            t += dis;
        }
        else if (dis > ca){
            return 0;
        }
        else {
            double ac_t = (ca - dis) ;
            ac_t = max(ac_t, 0.0);
            double rest_t = 2*(dis - ac_t);
            t += ac_t + rest_t;
        }
    }
    return t <= ti+1e-6;
}

int main() {
#ifdef D
    freopen("c.in", "r", stdin);
#endif
    in(ncar, nst, len, t);
    Rep(i,1,ncar) {
        in(price[i], cap[i]);
    }
    Rep(i,1,nst) {
        in(gas[i]);
    }
    sort(gas+1, gas+nst+1);
    gas[nst+1] = len;
    LL l = 0, r = 2e9;
    while (l < r) {
        LL m = (l+r)/2;
        if (ok(m, t)) {
            r = m;
        }
        else {
            l = m+1;
        }
    }

    // printf("need at least %d\n", l);

    int ans = INF;
    Rep(i,1,ncar) {
        if (l <= cap[i]) {
            ans = min(price[i], ans);
        }
    }

    if (ans == INF) puts("-1");
    else out(ans, "\n");

    return 0;
}
