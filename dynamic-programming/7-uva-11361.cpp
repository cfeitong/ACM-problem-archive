
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

int memo[20][200][200];
int A, B, K;

int pow(int a, int n) {
    int ret = 1;
    while (n--) {
        ret *= a;
    }
    return ret;
}

int M(int t) {
    int v = t / K;
    if (v <= 0)
        t += (-v+10)*K;
    return t%K;
}

int nc;
int calc(int n, int m1, int m2) {
    if (!n) return !m1 && !m2;
    nc++;
    if (memo[n][m1][m2] >= 0) return memo[n][m1][m2];
    int ret = 0;
    for (int i = 0; i <= 9; i++)
        ret += calc(n-1, M(m1-i), M(m2-i*pow(10,n-1)));
    return memo[n][m1][m2] = ret;
}

int count_digit(int n) {
    int ret = 0;
    while (n) {
        n /= 10;
        ret++;
    }
    return ret;
}

int solve(int n, int m1, int m2) {
    if (n == 0) return !m1 && !m2;
    int ret = 0;
    int cnt = count_digit(n)-1;
    int base = pow(10, cnt);
    for (int i = 0; i < n / base; i++) {
        ret += calc(cnt, M(m1-i), M(m2-i*base));
    }
    int t = n / base;
    return ret += solve(n%base, M(m1-t), M(m2-t*base));
}

int main() {
#ifdef D
    freopen("11361.in", "r", stdin);
#endif
    // K = 2;
    // int t; while (in(t)) printf("f(0~%d)=%d\n", pow(10,t), calc(t,0,0));
    int T; in(T);
    while (T--) {
        nc=0;
        memset(memo, -1, sizeof(memo));
        in(A,B,K);
        if (K > 100) {
            puts("0");
            continue;
        }
        int bb = solve(B,0,0), aa = solve(A-1,0,0);
        // printf("bb=%d,aa=%d\n", bb, aa);
        int ans = bb-aa;
        // printf("nc=%d\n",nc);
        out(ans, '\n');
    }
    return 0;
}
