
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

vector<pair<LL,LL>> exps;
LL D;
typedef string::iterator Iter;

LL parse_LL(Iter& it) {
    while (isspace(*it)) it++;
    LL ret = 0;
    while (isdigit(*it)) {
        ret *= 10;
        ret += *it - '0';
        it++;
    }
    while (isspace(*it)) it++;
    return ret;
}

void parse_exp(Iter& it) {
    while (isspace(*it)) it++;
    LL c = 1, e = 0;
    if (*it == '-') c = -1, it++;
    else if (*it == '+') c = 1, it++;
    while (isspace(*it)) it++;
    if (isdigit(*it)) c = c*parse_LL(it);
    while (isspace(*it)) it++;
    if (*it == 'n') it++, e=1;
    else if (*it == '-' || *it == '+') e = 0;
    while (isspace(*it)) it++;
    if (*it == '^') {
        it++;
        e = parse_LL(it);
    }
    while (isspace(*it)) it++;
    exps.pb({c,e});
}

LL pow_mod(LL a, LL b) {
    if (!b) return 1;
    LL ret = pow_mod(a, b/2);
    ret = ret*ret % D;
    if (b&1) ret = ret*a % D;
    return ret;
}

bool check(LL k) {
    LL acc = 0;
    for (auto e : exps) {
        acc += e.F * pow_mod(k, e.S) % D;
        acc %= D;
    }
    return acc == 0;
}

int main() {
    #ifdef DD
    freopen("4119.in", "r", stdin);
    #endif
    string input;
    LL kase = 0;
    while (getline(cin, input)) {
        if (input[0] == '.') break;
        kase++; out("Case ", kase, ": ");
        exps.clear();
        Iter it = begin(input);
        while (isspace(*it) || *it == '(') it++;
        while (*it != ')') {
            parse_exp(it);
        }
        it++;
        while (isspace(*it)) it++;
        while (isspace(*it) || *it == '/') it++;
        while (isspace(*it)) it++;
        D = parse_LL(it);
        bool ok = 1;
        Rep(i,1,101) {
            if (!check(i)) {
                puts("Not always an integer");
                ok = 0;
                break;
            }
        }
        if (ok) puts("Always an integer");
        #ifdef DD
        cout << input << endl;
        for (auto e : exps) {
            printf("%+lldn^%lld",e.F,e.S);
        }
        puts("");
        #endif
    }
    return 0;
}
