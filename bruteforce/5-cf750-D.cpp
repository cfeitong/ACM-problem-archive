#include <unordered_set>
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

int n, t[40];
int g[1000][1000];

int dy[] = {-1,-1,0, 1, 1,  1,  0, -1};
int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};

struct T {
    int y; int x; int d;
    bool operator == (const T o) const {
        vector<int> a{y,x,d};
        vector<int> b{o.y,o.x,o.d};
        return a == b;
    }
    bool operator < (const T o) const {
        vector<int> a{y,x,d};
        vector<int> b{o.y,o.x,o.d};
        return a < b;
    }
};

set<T> to_do;

int& p(int y, int x) {
    assert(0 <= 500+y && 500+y < 1000);
    assert(0 <= 500+x && 500+x < 1000);
    return g[500+y][500+x];
}

void expand(int y, int x, int l, int d) {
    Rep(i,0,l) {
        p(y+i*dy[(d+1)%8], x+i*dx[(d+1)%8]) = 1;
        p(y+i*dy[(d+7)%8], x+i*dx[(d+7)%8]) = 1;
    }
    to_do.insert(T{y+l*dy[(d+1)%8], x+l*dx[(d+1)%8], (d+1)%8});
    to_do.insert(T{y+l*dy[(d+7)%8], x+l*dx[(d+7)%8], (d+7)%8});
}

set<T> vis;
void bfs() {
    typedef pair<T,int> C;
    vis.clear();
    queue<C> q;
    q.push({T{0, 0, 0},0});
    vis.insert({0,0,0});
    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        int y = cur.F.y, x = cur.F.x;
        rep(i,0,t[cur.S]) {
            p(y, x) = 1;
            y += dy[cur.F.d];
            x += dx[cur.F.d];
        }
        y -= dy[cur.F.d];
        x -= dx[cur.F.d];
        int nd1 = (cur.F.d+1)%8;
        int nd2 = (cur.F.d+7)%8;
        T nt1 {y+dy[nd1], x+dx[nd1], nd1};
        T nt2 {y+dy[nd2], x+dx[nd2], nd2};
        if (vis.find(nt1) == end(vis)) {
            vis.insert(nt1);
            q.push({nt1, cur.S+1});
        }
        if (vis.find(nt2) == end(vis)) {
            vis.insert(nt2);
            q.push({nt2, cur.S+1});
        }
    }
}

int main() {
#ifdef D
    freopen("d.in", "r", stdin);
#endif
    in(n); rep(i,0,n) in(t[i]);
    rep(i,0,t[0]) {
        p(-i,0) = 1;
    }
    to_do.insert(T{-t[0]+1,0,0});
    rep(i,1,n) {
        auto last = to_do;
        to_do.clear();
        for (auto it : last) {
            expand(it.y, it.x, t[i], it.d);
        }
    }
    // bfs();

    int ans = 0;
    rep(i,0,1000) rep(j,0,1000) {
        ans += g[i][j];
    }
    out(ans, '\n');
    return 0;
}
