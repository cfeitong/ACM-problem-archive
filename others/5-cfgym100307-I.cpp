
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

bool query(int l, int r) {
    printf("check %d %d\n", l, r);
    fflush(stdout);
    char response[100];
    in(response);
    return response[0] == 'Y';
}

int P,V;
const int N = 1e5+5;
int L[N], R[N];

void debug() {
    printf("L[]: ");
    Rep(v,0,V) {
        L[v] > R[v] ? printf("-1 ") : printf("%d ", L[v]);
    }
    puts("");
    printf("R[]: ");
    Rep(v,0,V) {
        L[v] > R[v] ? printf("-1 ") : printf("%d ", R[v]);
    }
    puts("");
}

int main() {
    in(P,V);
    int clc = 0;
    Rep(v,0,V) {
        L[v] = 0;
        R[v] = P;
    }
    while (1) {
        int l=INF, r=0;
        int jdg = 0, eq = 0;
        Rep(v,0,V) {
            if (L[v] <= R[v]) {
                l = min(L[v], l);
                r = max(R[v], r);
                jdg += R[v]-L[v];
                eq += (R[v] == L[v]);
            }
        }
        if (!jdg && eq == 1) break;
        int m = (l+r)/2;
        bool in_l = query(0, m);
        if (in_l) {
            Rep(v,0,V) {
                R[v] = min(R[v], m);
            }
        }
        else {
            Rep(v,0,V) {
                L[v] = max(L[v], m+1);
            }
        }
        Rep(v,0,V) {
            L[v] += v;
            R[v] += v;
        }
        // debug();
        clc++;
    }

    Rep(v,0,V) {
        if (L[v] == R[v]) {
            printf("answer %d\n", L[v]);
            break;
        }
    }

    return 0;
}
