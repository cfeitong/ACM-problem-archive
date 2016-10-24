/*
  ID: cfeiton1
  PROG: range
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

bool in(LD       &v) {return scanf("%Lf",  &v)!=EOF;}
bool in(LL       &v) {return scanf("%lld", &v)!=EOF;}
bool in(int      &v) {return scanf("%d",   &v)!=EOF;}
bool in(char     *v) {return scanf("%s",    v)!=EOF;}
bool in(char     &v) {return scanf("%c",   &v)!=EOF;}
bool in(unsigned &v) {return scanf("%u",   &v)!=EOF;}
bool in(string   &v) {return (bool)(cin >> v);}
template<typename T, typename... Args> bool in(T &v, Args &...args) {bool ret = in(v); return ret && in(args...);}

void out(LD       v) {printf("%Lf",  v);}
void out(LL       v) {printf("%lld", v);}
void out(int      v) {printf("%d",   v);}
void out(char     v) {printf("%c",    v);}
void out(unsigned v) {printf("%u",   v);}
void out(string   v) {printf("%s",    v.c_str());}
template<typename T> void out(vector<T> &v) {for (int i = 0; i < (int)v.size(); i++) out(v[i]);}
template<typename T, typename... Args> void out(T v, Args ...args) {out(v); out(args...);}

const int N = 300;
char g[N][N];
int n;
int c[N][N];

int query(int x, int y) {
    int sum = 0;
    for (int i = y; i; i -= i&-i) {
        for (int j = x; j; j -= j&-j) {
            sum += c[i][j];
        }
    }
    return sum;
}

void update(int x, int y) {
    for (int i = y; i < N; i += i&-i) {
        for (int j = x; j < N; j += j&-j) {
            c[i][j]++;
        }
    }
}

int find(int k) {
    int ret = 0;
    Rep(i,1,n) Rep(j,1,n) {
        if (i+k <= n+1 && j+k <= n+1) {
            int cur = query(i+k-1, j+k-1) - query(i+k-1, j-1) - query(i-1, j+k-1) + query(i-1, j-1);
            if (cur == k*k)
                ret++;
        }
    }
    return ret;
}

int main() {
  freopen("range.in", "r", stdin);
#ifndef DEBUG
  freopen("range.out", "w", stdout);
#endif

  in(n);
  rep2(i,j, 0,N, 0,N) g[i][j] = '0';
  Rep(i,1,n) {
      in(g[i]+1);
      g[i][n+1] = '0';
  }
  Rep(i,1,n) Rep(j,1,n) if (g[i][j] == '1') update(i,j);

  Rep(i,2,n) {
      int ans = find(i);
      if (ans)
          out(i, ' ', ans, '\n');
  }

  return 0;
}
