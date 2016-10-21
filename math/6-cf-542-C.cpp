
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

void in(LD       &v) {scanf("%Lf",  &v);}
void in(LL       &v) {scanf("%lld", &v);}
void in(int      &v) {scanf("%d",   &v);}
void in(char     *v) {scanf("%s",    v);}
void in(char     &v) {scanf("%c",   &v);}
void in(unsigned &v) {scanf("%u",   &v);}
void in(string   &v) {cin >> v;}
template<typename T, typename... Args> void in(T &v, Args &...args) {in(v); in(args...);}

void out(LD       v) {printf("%Lf ",  v);}
void out(LL       v) {printf("%lld ", v);}
void out(int      v) {printf("%d ",   v);}
void out(char     v) {printf("%c",    v);}
void out(unsigned v) {printf("%u ",   v);}
void out(string   v) {printf("%s",    v.c_str());}
template<typename T> void out(vector<T> &v) {for (int i = 0; i < (int)v.size(); i++) out(v[i]);}
template<typename T, typename... Args> void out(T v, Args ...args) {out(v); out(args...);}

int n;
const int N = 202;
int a[N];
LL pre[N], cir[N];

void calc(LL k) {
    map<LL,LL> sav;
    int cur_n = a[k], cur_i = 1;
    while (sav.find(cur_n) == sav.end()) {
        sav[cur_n] = cur_i++;
        cur_n = a[cur_n];
    }
    cir[k] = cur_i - sav[cur_n];
    pre[k]=  sav[cur_n];
}

LL gcd(LL a, LL b) {
    if (!b) return a;
    return gcd(b, a%b);
}

LL lcm(LL a, LL b) {
    return a / gcd(a, b) * b;
}

int main() {
#ifdef DEBUG
    freopen("c.in", "r", stdin);
#endif // DEBUG
    in(n);
    Rep(i,1,n) {
        in(a[i]);
    }

    Rep(i,1,n)
        calc(i);

    LL ans = 1;
    Rep(i,1,n) {
        ans = lcm(ans, cir[i]);
    }

    LL max_pre = 0;
    Rep(i,1,n) {
        max_pre = max(max_pre, pre[i]);
    }

    if (ans < max_pre) {
        ans = max_pre / ans * ans + (max_pre%ans!=0) * ans;
    }

    out(ans, '\n');

    return 0;
}
