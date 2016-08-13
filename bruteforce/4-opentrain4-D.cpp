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

#define UP 2441440

int fre[20], sel[20];
int n, k;

bool check(int cur) {
  int cnt = k;
  int nn = n;
  int pos = 0;
  while (1) {
    int t = (cur-1) % nn;
    while (t--) {
      pos = (pos+1) % n;
      while (sel[pos]) {
        pos = (pos+1) % n;
      }
    }
    if (!fre[pos]) return 0;
    sel[pos] = 1;
    cnt--, nn--;
    if (!cnt) break;
    pos = (pos+1) % n;
    while (sel[pos]) {
      pos = (pos+1) % n;
    }
  }
  return 1;
}

int main() {
  // freopen("e.in", "r", stdin);

  in_i2(n, k);
  rep(i, 0, k) {
    int t; in_i(t);
    fre[t-1] = 1;
  }

  bool ok = 0;
  int i;
  for (i = 1; i < UP; i++) {
    memset(sel, 0, sizeof(sel));
    if (check(i)) {
      ok = 1; break;
    }
  }

  if (!ok) printf("-1\n");
  else printf("%d\n", i%2013);


  return 0;
}
