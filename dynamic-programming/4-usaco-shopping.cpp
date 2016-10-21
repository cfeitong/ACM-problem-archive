/*
  ID: cfeiton1
  PROG: shopping
  LANG: C++11
*/


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

void out(LD       v) {printf("%Lf",  v);}
void out(LL       v) {printf("%lld", v);}
void out(int      v) {printf("%d",   v);}
void out(char     v) {printf("%c",    v);}
void out(unsigned v) {printf("%u",   v);}
void out(string   v) {printf("%s",    v.c_str());}
template<typename T> void out(vector<T> &v) {for (int i = 0; i < (int)v.size(); i++) out(v[i]);}
template<typename T, typename... Args> void out(T v, Args ...args) {out(v); out(args...);}

int codemap[1000], codecnt, remap[10];
int dp[6][6][6][6][6];
int s, b;
struct Offer {
    int use[10];
    int price;
} offer[102];
int price[10];
int need[10];

int main() {
  freopen("shopping.in", "r", stdin);
#ifndef DEBUG
  freopen("shopping.out", "w", stdout);
#endif
  in(s);
  rep(i,0,s) {
      int n; in(n);
      rep(j,0,n) {
          int c, k; in(c, k);
          if (!codemap[c]) {
              codemap[c] = ++codecnt;
              remap[codecnt] = c;
          }
          offer[i].use[codemap[c]] = k;
      }
      int p; in(p);
      offer[i].price = p;
  }
  in(b);
  rep(i,0,b) {
      int c, k, p; in(c, k, p);
      if (!codemap[c]) {
          codemap[c] = ++codecnt;
          remap[codecnt] = c;
      }
      price[codemap[c]] = p;
      need[codemap[c]] = k;
  }

  memset(dp, 0x3f, sizeof(dp));
  dp[0][0][0][0][0] = 0;

#define MINI(a, b) (a) = min((a), (b))

  Rep(i,0,need[1]) Rep(j,0,need[2])
      Rep(k, 0, need[3]) Rep(l, 0, need[4]) Rep(m, 0, need[5]) {
      rep(n, 0, s) {
          auto &cur = offer[n];
          int ii, jj, kk, ll, mm;
          if ((ii=i+cur.use[1]) <= need[1] &&
              (jj=j+cur.use[2]) <= need[2] &&
              (kk=k+cur.use[3]) <= need[3] &&
              (ll=l+cur.use[4]) <= need[4] &&
              (mm=m+cur.use[5]) <= need[5]) {
              MINI(dp[ii][jj][kk][ll][mm], dp[i][j][k][l][m]+cur.price);
          }
      }
      if (i+1 <= need[1]) MINI(dp[i+1][j][k][l][m], dp[i][j][k][l][m]+price[1]);
      if (j+1 <= need[2]) MINI(dp[i][j+1][k][l][m], dp[i][j][k][l][m]+price[2]);
      if (k+1 <= need[3]) MINI(dp[i][j][k+1][l][m], dp[i][j][k][l][m]+price[3]);
      if (l+1 <= need[4]) MINI(dp[i][j][k][l+1][m], dp[i][j][k][l][m]+price[4]);
      if (m+1 <= need[5]) MINI(dp[i][j][k][l][m+1], dp[i][j][k][l][m]+price[5]);
  }

  out(dp[need[1]][need[2]][need[3]][need[4]][need[5]], '\n');

  return 0;
}
