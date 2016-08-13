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

#define INF 0x3f3f3f3f
#define pb push_back
#define pf push_front
#define mp make_pair
#define mt make_tuple
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

#define N 2000

int n,k;

int rela[N][N];
bool ban[N];

int main() {
  // freopen("h.in", "r", stdin);

  in_i2(n, k);
  rep(i, 1, n+1) {
    int t = 0;
    rep(j, 1, n+1) {
      in_i(rela[i][j]);
      t += rela[i][j];
    }
    if (t < k) ban[i] = 1;
  }

  bool remv = 1;
  while (remv) {
    remv = 0;

    rep(i, 1, n+1) {
      if (!ban[i]) {
        int cnt1 = 0, cnt2 = 0;
        rep(j, 1, n+1) if (i != j) {
          if (!ban[j]) {
            cnt1 += !rela[i][j];
            cnt2 += rela[i][j];
          }
        }
        if (cnt1 < k || cnt2 < k) {
          ban[i] = 1;
          remv = 1;
        }
      }
    }
  }

  int cnt = 0;
  rep(i, 1, n+1) {
    cnt += !ban[i];
  }
  printf("%d\n", cnt);

  rep(i, 1, n+1) {
    if (!ban[i]) printf("%d ", i);
  }
  puts("");

  return 0;
}
