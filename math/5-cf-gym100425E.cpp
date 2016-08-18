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
#define N 200000

int n;

LD p;
string s;
int T;

LD q_pow(LD k, int times) {
  if (!times) return 1;
  LD ret = q_pow(k, times/2);
  ret *= ret;
  if (times%2) ret *= k;
  return ret;
}

int main() {
  speedup;
  // freopen("e.in", "r", stdin);

  cin >> n;
  // in_i(n);

  LD ans = 0, L = 1, R = 0;

  rep(i, 0, n) {
    cin >> T >> s >> p;
    // in_i(T); scanf(" %c ", &s); in_d(p);
    LD tmp = 0.5 + q_pow(1-2*p, T)*0.5;

    if (s == "L") {
      ans += tmp * L + (1-tmp) * R;
      L = 1-tmp; R = tmp;
    }
    else if (s == "R") {
      ans += tmp * R + (1-tmp) * L;
      R = 1-tmp; L = tmp;
    }
    else {
      1/0;
    }
  }

  cout.precision(10);
  cout << ans << endl;
  // printf("%.10Lf\n", ans);

  return 0;
}
