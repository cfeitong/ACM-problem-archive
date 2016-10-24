
#include <functional>
#include <assert.h>
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

void out(LD       v) {printf("%Lf",  v);}
void out(LL       v) {printf("%lld", v);}
void out(int      v) {printf("%d",   v);}
void out(char     v) {printf("%c",    v);}
void out(unsigned v) {printf("%u",   v);}
void out(string   v) {printf("%s",    v.c_str());}
template<typename T> void out(vector<T> &v) {for (int i = 0; i < (int)v.size(); i++) out(v[i]);}
template<typename T, typename... Args> void out(T v, Args ...args) {out(v); out(args...);}

LL n;

const int N = 10;
const LL MOD = 1e9+7;

struct Mat {
    LL a[N][N];
    int row, col;

    Mat(const Mat &o) = default;
    Mat(int r, int c) : row(r), col(c) {memset(a,0,sizeof(a));}
    Mat() : Mat(0,0) {}

    Mat operator * (const Mat o) const {
        assert(col == o.row);
        Mat ret(row, o.col);
        rep(i,0,row) rep(j,0,o.col) rep(k,0,col) {
            ret.a[i][j] += a[i][k] * o.a[k][j] % MOD;
            ret.a[i][j] %= MOD;
        }
        return ret;
    }

    void operator *= (const Mat &o) {
        Mat ret(row, o.col);
        rep(i,0,row) rep(j,0,o.col) rep(k,0,col) {
            ret.a[i][j] += a[i][k] * o.a[k][j] % MOD;
            ret.a[i][j] %= MOD;
        }
        *this = ret;
    }

    Mat operator ^ (const LL n) {
        if (n == 1) return *this;
        Mat ret = *this ^ (n/2);
        Mat nret = ret * ret;
        if (n & 1) nret *= *this;
        return nret;
    }

    LL & at(int r, int c) {
        return a[r][c];
    }

    void print() const {
        rep(i,0,row) {
            rep(j,0,col) {
                out(a[i][j], ' ');
            }
            out('\n');
        }
    }
};

int main() {
    while (cin >> n) {
        n--;
        if (!n) {
            out(2, '\n');
            continue;
        }

        Mat co(2,2);
        co.a[0][0] = 1;
        co.a[0][1] = -2;
        co.a[1][0] = -1;
        co.a[1][1] = 1;

        Mat ab(2,1);
        ab.at(0,0) = 1;
        ab.at(1,0) = -1;
        co = co ^ n;
        ab = co * ab;

        if (!(n & 1)) {
            LL b = ab.at(1,0);
            b *= 2*b%MOD;
            b %= MOD;
            out(b, '\n');
        }
        else {
            LL a = ab.at(0,0);
            a *= a;
            a %= MOD;
            out(a, '\n');
        }

    }
    return 0;
}
