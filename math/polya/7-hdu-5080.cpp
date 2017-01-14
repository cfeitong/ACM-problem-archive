
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

struct Pt;

const LD EPS = 1e-3;
const LD PI = 3.1415926535;
const LL MOD = 1e9+7;

LL qpow(LL k, LL t) {
    if (t == 0) return 1;
    LL ret = qpow(k, t / 2);
    ret = ret * ret % MOD;
    if (t&1) ret = ret * k % MOD;
    return ret % MOD;
}

LL inv(LL k) {
    return qpow(k, MOD-2);
}

LD dist(Pt a, Pt b);


int sign(LD x) {
    if (x < -EPS) return -1;
    if (x > EPS) return 1;
    return 0;
}

struct Pt {
    LD x, y;
    int id;
    bool operator<(const Pt& rhs) const {
        if (sign(x - rhs.x) == 0) {
            return sign(sign(y - rhs.y) < 0);
        }
        return sign(x - rhs.x) < 0;
    }
    bool operator==(const Pt& rhs) const {
        return sign(x-rhs.x) == 0 && sign(y-rhs.y) == 0;
    }
    bool operator!=(const Pt& rhs) const {
        return !(*this == rhs);
    }
    bool operator>(const Pt& rhs) const {
        return !(*this == rhs) && !(*this < rhs);
    }
    Pt rot(LD angle) { // anti-clockwise
        if (*this == Pt{0,0,-1}) return Pt{0,0,id};
        LD arc = atan2(y,x);
        arc += angle;
        Pt ret{len()*cos(arc), len()*sin(arc), id};
        return ret;
    }
    LD len() {
        return dist(*this, Pt{0,0,-1});
    }
};

struct Edg {
    Pt a, b;
    int id;
    Edg(Pt _a, Pt _b, int _id) : id(_id) {
        if (_a > _b) swap(_a, _b);
        a = _a; b = _b;
    }
    bool operator<(const Edg& rhs) const {
        if (a == rhs.a) return b < rhs.b;
        return a < rhs.a;
    }
    bool operator==(const Edg& rhs) const {
        return a == rhs.a && b == rhs.b;
    }
    Edg rot(LD angle) {
        return Edg(a.rot(angle), b.rot(angle), id);
    }
};

LD dist(Pt a, Pt b) {
    LD dx = a.x-b.x;
    LD dy = a.y-b.y;
    return sqrt(dx*dx+dy*dy);
}

LD angle_betwen(Pt a, Pt b) {
    LD a1 = atan2(a.y, a.x);
    LD a2 = atan2(b.y, b.x);
    return -a1+a2;
}

vector<Pt> ps;
vector<Edg> edgs;
int n, m, c;
int to[100];
bool used[100];


int loop() {
    fill(used, used+100, 0);
    int ret = 0;
    rep(i,0,n) {
        if (used[i]) continue;
        used[i] = 1;
        int cur = to[i];
        while (cur != i) {
            used[cur] = 1;
            cur = to[cur];
        }
        ret++;
    }
    return ret;
}

struct DB {
    LD v;
    bool operator==(const DB& rhs) const {
        return sign(v-rhs.v) == 0;
    }
    bool operator<(const DB& rhs) const {
        return sign(v-rhs.v) < 0;
    }
};

int main() {
#ifdef D
    freopen("5080.in", "r", stdin);
#endif
    int T; in(T);
    while (T--) {
        ps.clear();
        edgs.clear();
        fill(to, to+100, 0);
        in(n,m,c);
        LL ans = 0;
        LD mx=0, my=0;
        rep(i,0,n) {
            LD x, y; in(x, y);
            mx += x; my += y;
            ps.pb({x,y,i});
        }
        mx /= n; my /= n;
        rep(i,0,n) {
            ps[i].x -= mx;
            ps[i].y -= my;
        }
        rep(i,0,m) {
            int a, b; in(a,b);
            edgs.pb(Edg(ps[a-1], ps[b-1], i));
        }

        sort(all(ps));
        int cnt = 0;
        rep(i,0,4) {
            LD ang = PI/2 *i;
            vector<Pt> nps;
            vector<Edg> nedgs;
            for (auto it : edgs) {
                nedgs.pb(it.rot(ang));
            }
            for (auto it : ps) {
                nps.pb(it.rot(ang));
            }
            sort(all(ps)); sort(all(nps)); sort(all(edgs)); sort(all(nedgs));
            // printf("rot %.1Lf %s\n", ang/PI*180, (edgs==nedgs && ps==nps)?"YES":"NO");
            // rep(i,0,n) {
            //     printf("p[%d] = {%.1Lf,%.1Lf,%d}\n", i, ps[i].x, ps[i].y, ps[i].id);
            //     printf("np[%d] = {%.1Lf,%.1Lf,%d}\n", i, nps[i].x, nps[i].y, nps[i].id);
            // }
            // rep(i,0,m) if (!(edgs[i] == nedgs[i])) {
            //     auto c1 = edgs[i], c2 = nedgs[i];
            //     printf("seg[%d] = {{%.1Lf,%.1Lf}, {%.1Lf,%.1Lf}}\n",
            //            i, edgs[i].a.x, edgs[i].a.y, edgs[i].b.x, edgs[i].b.y);
            //     printf("nseg[%d] = {{%.1Lf,%.1Lf}, {%.1Lf,%.1Lf}}\n",
            //            i, nedgs[i].a.x, nedgs[i].a.y, nedgs[i].b.x, nedgs[i].b.y);
            // }
            if (nps != ps) continue;
            if (edgs != nedgs) continue;
            cnt++;
            rep(i,0,n) {
                to[nps[i].id] = ps[i].id;
            }
            // rep(i,0,n) printf("to[%d] = %d\n", i, to[i]);
            int p = loop();
            // out(c, "^", p, "=",qpow(c,p), '\n');
            ans = (ans+qpow(c, p)) % MOD;
        }
        // out(ans, ' ', cnt, '\n');
        // out("tot: ", ans, "/", cnt, "=", ans*inv(cnt)%MOD, "\n");
        out(ans*inv(cnt)%MOD, '\n');
        // out("-------------------------------------------------\n");
    }
    return 0;
}
