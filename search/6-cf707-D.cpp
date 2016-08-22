
#include <cassert>
#include <numeric>
#include <functional>
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
#include <tuple>
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
#define in_d(a) scanf("%Lf", &a)
#define in_d2(a,b) scanf("%Lf%Lf", &a, &b)
#define in_d3(a,b,c) scanf("%Lf%Lf%Lf", &a, &b, &c)
#define in_d4(a,b,c,d) scanf("%Lf%Lf%Lf%Lf", &a, &b, &c, &d)
#define in_i(a) scanf("%d", &a)
#define in_i2(a,b) scanf("%d%d", &a, &b)
#define in_i3(a,b,c) scanf("%d%d%d", &a, &b, &c)
#define in_i4(a,b,c,d) scanf("%d%d%d%d", &a, &b, &c, &d)
#define in_s(a) scanf("%s", a)
#define all(c) c.begin(), c.end()
#define rep(i, j, k) for (int i = (j); i < (int)(k); i++)
#define rep2(i,j, f1,t1, f2,t2) for (int i = (f1); i < (int)(t1); i++) for (int j = (f2); j < (int)(t2); j++)
#define Rep(i, j, k) for (int i = (j); i <= (int)(k); i++)
#define Rep2(i,j, f1,t1, f2,t2) for (int i = (f1); i <= (int)(t1); i++) for (int j = (f2); j <= (int)(t2); j++)
#define per(i, j, k) for (int i = (j); i >= (int)(k); i--)
#define out_i(a) printf("%d\n", a);
#define out_i2(a,b) printf("%d %d\n", a, b);
#define out_i3(a,b,c) printf("%d %d %d\n", a, b, c);
#define out_i4(a,b,c,d) printf("%d %d %d %d\n", a, b, c, d);
#define out_d(a) printf("%.10Lf\n", a);
#define out_d2(a,b) printf("%.10Lf %.10Lf\n", a, b);
#define out_d3(a,b,c) printf("%.10Lf %.10Lf %.10Lf\n", a, b, c);
#define out_d4(a,b,c,d) printf("%.10Lf %.10Lf %.10Lf %.10Lf\n", a, b, c, d);
#define out_s(s) printf("%s\n", s);
#define out_ci(c) if (!c.empty()) printf("%d", c[0]); rep(i, 1, c.size()) printf(" %d", c[i]); puts("")
#define out_cd(c) if (!c.empty()) printf("%.10Lf", c[0]); rep(i, 1, c.size()) printf(" %.10Lf", c[i]); puts("")
typedef long long LL;
typedef long double LD;
typedef pair<LL, LL> PLL;
typedef pair<int, int> PII;
typedef pair<LD, LD> PDD;
typedef vector<LD> VD;
typedef vector<PDD> VDD;
typedef vector< vector<PDD> > VVD;
typedef vector<LL> VL;
typedef vector<PLL> VLL;
typedef vector< vector<PLL> > VVL;
typedef vector<int> VI;
typedef vector<PII> VII;
typedef vector<vector<PII> > VVI;
#define N 2030

int n, m, q;
int ans[N*100];

struct Op {
  int t;
  int i, j;
} op[N*100];

VI son[N*100];
int pa[N*100];

int bc[N][N];

void dfs(int k, int cur) {
  int ncur = cur;

  if (op[k].t == 1) {
    if (!bc[op[k].i][op[k].j]) {
      bc[op[k].i][op[k].j] = 1;
      ans[k] = ++ncur;
      for (auto it : son[k]) dfs(it, ncur);
      bc[op[k].i][op[k].j] = 0;
    }
    else {
      ans[k] = ncur;
      for (auto it : son[k]) dfs(it, ncur);
    }
  }

  else if (op[k].t == 2) {
    if (bc[op[k].i][op[k].j]) {
      bc[op[k].i][op[k].j] = 0;
      ans[k] = --ncur;
      for (auto it : son[k]) dfs(it, ncur);
      bc[op[k].i][op[k].j] = 1;
    }
    else {
      ans[k] = ncur;
      for (auto it : son[k]) dfs(it, ncur);
    }
  }

  else if (op[k].t == 3) {
    Rep(i, 1, m) {
      ncur += bc[op[k].i][i] ? -1 : 1;
      bc[op[k].i][i] = !bc[op[k].i][i];
    }
    ans[k] = ncur;
    for (auto it : son[k]) dfs(it, ncur);
    Rep(i, 1, m) bc[op[k].i][i] = !bc[op[k].i][i];
  }

  else if (op[k].t == 4) {
    ans[k] = ans[pa[k]];
    for (auto it : son[k]) dfs(it, ans[pa[k]]);
  }
}

int main() {
  // freopen("d.in", "r", stdin);

  in_i3(n, m, q);
  Rep(i,1, q) {
    int t; in_i(t);
    int a=-1, b=-1;
    if (t == 1 || t == 2) in_i2(a, b);
    else in_i(a);
    op[i] = (Op) {t, a, b};

    if (t == 4) {
      pa[i] = a;
      son[a].pb(i);
    }
    else {
      pa[i] = i-1;
      son[i-1].pb(i);
    }
  }


  for (auto it : son[0]) {
    dfs(it,0);
  }

  Rep(i, 1, q) {
    printf("%d\n", ans[i]);
  }

  return 0;
}
