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
#define rep(i, j, k)                            \
  for (int i = (j); i < (k); i++)
typedef long long LL;
typedef long double LD;
typedef pair<LL, LL> PLL;
typedef pair<int, int> PII;
typedef pair<LD, LD> PDD;
typedef vector<LD> VD;
typedef vector<LD, LD> VDD;
typedef vector< vector<LD, LD> > VVD;
typedef vector<LL> VL;
typedef vector<LL, LL> VLL;
typedef vector< vector<LL, LL> > VVL;
typedef vector<int> VI;
typedef vector<int, int> VII;
typedef vector< vector<int, int> > VVI;
#define N 100000

int n, a, b;
struct T {
  int t, w, i;
} cu[N];
VI sel;

int main() {
  // freopen("i.in", "r", stdin);

  in_i3(n, a, b);

  rep(i, 1, n+1) {
    in_i2(cu[i].t, cu[i].w);
    cu[i].i = i;
  }

  sort(cu+1, cu+n+1, [](T a, T b) { return a.w < b.w; });

  int aa = a, bb = b, rest = a+b;

  rep(i, 1, n+1) {
    if (cu[i].t == 1 && aa > 0 && rest > 0) {
      rest--, aa--; sel.pb(i);
    }
    else if (cu[i].t == 2 && bb > 0 && rest > 0) {
      rest--, bb--; sel.pb(i);
    }
    else if (cu[i].t == 3 && rest > 0) {
      rest--; sel.pb(i);
    }
  }

  int power = 0;
  for (auto it : sel) power += cu[it].w;
  printf("%d %d\n", (int)sel.size(), power);

  aa = a, bb = a+b;
  for (auto it : sel) {
    if (cu[it].t == 1) {
      printf("%d %d\n", cu[it].i, aa);
      aa--;
    }
    else if (cu[it].t == 2) {
      printf("%d %d\n", cu[it].i, bb);
      bb--;
    }
  }

  for (auto it : sel) {
    if (cu[it].t == 3) {
      int t = 0;
      if (aa > 0) {
        t = aa--;
      }
      else {
        t = bb--;
      }
      printf("%d %d\n", cu[it].i, t);
    }
  }

  return 0;
}
