
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
#define in_l(a) scanf("%lld", &a)
#define in_l2(a,b) scanf("%lld%lld", &a, &b)
#define in_l3(a,b,c) scanf("%lld%lld%lld", &a, &b, &c)
#define in_l4(a,b,c,d) scanf("%lld%lld%lld%lld", &a, &b, &c, &d)
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
#define out_l(a) printf("%lld\n", a);
#define out_l2(a,b) printf("%lld %lld\n", a, b);
#define out_l3(a,b,c) printf("%lld %lld %lld\n", a, b, c);
#define out_l4(a,b,c,d) printf("%lld %lld %lld %lld\n", a, b, c, d);
#define out_d(a) printf("%.10Lf\n", a);
#define out_d2(a,b) printf("%.10Lf %.10Lf\n", a, b);
#define out_d3(a,b,c) printf("%.10Lf %.10Lf %.10Lf\n", a, b, c);
#define out_d4(a,b,c,d) printf("%.10Lf %.10Lf %.10Lf %.10Lf\n", a, b, c, d);
#define out_s(s) printf("%s\n", s);
#define out_ci(c) if (!c.empty()) printf("%d", c[0]); rep(i, 1, c.size()) printf(" %d", c[i]); puts("")
#define out_cd(c) if (!c.empty()) printf("%.10Lf", c[0]); rep(i, 1, c.size()) printf(" %.10Lf", c[i]); puts("")
#define out_cl(c) if (!c.empty()) printf("%lld", c[0]); rep(i, 1, c.size()) printf(" %lld", c[i]); puts("")
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
#define N 203000

vector<string> vs;
char s[30];
int vis[1<<16];

int s2i(string s) {
  int ret = 0;
  for (auto it : s) {
    ret <<= 1;
    ret += it-'0';
  }
  return ret;
}

int main() {
  freopen("f.in", "r", stdin);
  int T;
  in_i(T);
  while (T--) {
    vs.clear();
    int n; in_i(n);
    rep(i, 0, 1<<n) {
      in_s(s);
      vs.pb(string(s));
    }

    bool ok = 1;
    auto tmp = vs;
    for (auto &it : tmp[0]) if (it == '?') it = '0';
    memset(vis, 0, sizeof(vis));
    vis[s2i(tmp[0])] = 1;

    for (int i = 1; i < 1 << n; i++) {
      int cnt = 0;
      for (int j = 0;  j< n; j++) {
        if (tmp[i][j] == '?') continue;
        if (tmp[i][j] != tmp[i-1][j]) cnt++;
      }
      if (cnt > 1) {
        ok = 0;
        break;
      }
      for (int j = 0; j < n; j++) {
        if (tmp[i][j] == '?') {
          if (cnt) {
            tmp[i][j] = (tmp[i-1][j] == '1' ? '1' : '0');
          }
          else {
            tmp[i][j] = (tmp[i-1][j] == '1' ? '0' : '1');
          }
          if (!vis[s2i(tmp[i])]) {
            vis[s2i(tmp[i])] = 1;
          }
          else {
            ok = 0; break;
          }
        }
      }
    }

    int cnt = 0;
    for (int j = 0; j < n; j++) {
      if (tmp[0][j] != tmp[(1<<n)-1][j]) cnt++;
    }
    if (cnt != 1) ok = 0;

    if (ok) {
      for (auto it : tmp) {
        puts(it.c_str());
      }
      continue;
    }

    ok = 1;
    memset(vis, 0, sizeof(vis));
    tmp = vs;
    for (auto &it : tmp[0]) if (it == '?') it = '1';
    vis[s2i(tmp[0])] = 1;

    for (int i = 1; i < 1 << n; i++) {
      int cnt = 0;
      for (int j = 0;  j< n; j++) {
        if (tmp[i][j] == '?') continue;
        if (tmp[i][j] != tmp[i-1][j]) cnt++;
      }
      if (cnt > 1) {
        ok = 0;
        break;
      }
      for (int j = 0; j < n; j++) {
        if (tmp[i][j] == '?') {
          if (cnt) {
            tmp[i][j] = (tmp[i-1][j] == '1' ? '1' : '0');
          }
          else {
            tmp[i][j] = (tmp[i-1][j] == '1' ? '0' : '1');
          }
          if (!vis[s2i(tmp[i])]) {
            vis[s2i(tmp[i])] = 1;
          }
          else {
            ok = 0; break;
          }
        }
      }
    }

    cnt = 0;
    for (int j = 0; j < n; j++) {
      if (tmp[0][j] != tmp[(1<<n)-1][j]) cnt++;
    }
    if (cnt != 1) ok = 0;

    if (ok) {
      for (auto it : tmp) {
        puts(it.c_str());
      }
      continue;
    }
    else {
      puts("impossible");
    }

  }

  return 0;
}
