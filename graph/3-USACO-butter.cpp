/*
  ID: cfeiton1
  PROG: butter
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

#define pb       push_back
#define pf       push_front
#define mp       make_pair
#define mt       make_tuple
#define INF      0x3f3f3f3f
#define F        first
#define S        second
#define speedup  ios_base::sync_with_stdio(0);cin.tie(0)
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


const int N = 1000;

int g[N][N];
VI to[N];

int n,p,c;
int d[N];
int pas[N];

void dij(int k) {
    memset(d, 0x3f, sizeof(d));
    priority_queue<PII, vector<PII>, greater<PII> > q;
    q.push({0,k}); d[k] = 0;
    while (!q.empty()) {
        auto cur = q.top(); q.pop();
        for (auto i : to[cur.S]) {
            if (d[i] > g[cur.S][i] + d[cur.S]) {
                d[i] = g[cur.S][i] + d[cur.S];
                q.push({d[i], i});
            }
        }
    }
}

int main() {
  freopen("butter.in", "r", stdin);
#ifndef DEBUG
  freopen("butter.out", "w", stdout);
#endif

  memset(g, 0x3f, sizeof(g));

  in(n,p,c);
  Rep(i,1,n) {
      int t; in(t);
      pas[t]++;
  }
  rep(i,0,c) {
      int a,b,c; in(a,b,c);
      g[a][b] = g[b][a] = c;
      to[a].pb(b); to[b].pb(a);
  }


  int ans = INF;
  Rep(i,1,p) {
      dij(i);
      int cur = 0;
      Rep(i,1,p) {
          cur += d[i] * pas[i];
      }
      ans = min(cur, ans);
  }

  printf("%d\n", ans);

  return 0;
}
