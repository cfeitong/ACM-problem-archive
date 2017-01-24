

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

const int N = 3e6+5;
char s[N];
LL ans;
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};

int ox = N/2, oy = N/2;

struct vec {
    LL x, y;
    vec operator-(vec rhs) {
        return vec{x-rhs.x, y-rhs.y};
    }
};

// (o-a) x (o-b)
LL xmul(vec o, vec a, vec b) {
    vec t1 = o-a;
    vec t2 = o-b;
    return t1.x*t2.y - t1.y*t2.x;
}

LL dir_areax2(vec b, vec c) {
    vec o{0,0};
    return xmul(o,b,c);
}

int main() {
    #ifdef D
    freopen("c.in", "r", stdin);
    #endif
    while (in(s)) {
        int x = ox, y = oy;
        int l = strlen(s);
        LL area = 0;
        ans = 0;
        rep(i,0,l) {
            int d = s[i]-'0';
            int ny = y + dy[d];
            int nx = x + dx[d];
            area += dir_areax2({x,y}, {nx,ny});
            y = ny; x = nx;
        }
        ans += l;
        ans += (area-l+2)/2;
        out(ans, '\n');
    }
    return 0;
}