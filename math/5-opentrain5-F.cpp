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
#define N 503000

LD p[N];
int lt[N], et[N];
int n, m;

priority_queue<PII, vector<PII>, greater<PII> > q;

int main() {
  // freopen("f.in", "r", stdin);

  in_i2(n, m);

  rep(i, 0, n) {
    in_i(lt[i]); in_d(p[i]);
  }

  rep(i, 0, m) q.push({lt[i], i});

  int nt = 0, tp = m;
  while (!q.empty()) {
    auto cur = q.top(); q.pop();
    et[cur.S] = cur.F;
    nt = cur.F;
    if (tp < n) {
      q.push({nt+lt[tp], tp});
      tp++;
    }
  }

  // rep(i, 0, n) printf("%d%c", et[i], " \n"[i==n-1]);

  LD ans = 0, pre = 1;
  int cur = 0;

  rep(i, 0, n) {
    cur = max(cur, et[i]);
    ans += pre * (1-p[i]) * cur;
    pre *= p[i];
  }
  ans += pre * cur;

  printf("%.10Lf\n", ans);

  return 0;
}
