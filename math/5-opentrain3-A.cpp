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

#define N 4000000

char s[N];
int len;
int a1,b1,a2,b2;

int ans[N];
int sz;

int main() {
  // freopen("a.in", "r", stdin);

  // while (in_s(s) > 0) {
  in_s(s);
  memset(ans, 0, sizeof(ans));
  len = strlen(s);
  rep(i, 0, len) {
    ans[i] += s[len-i-1] - '0';
  }
  in_s(s); len = strlen(s);
  rep(i, 0, len) {
    ans[i] += s[len-i-1] - '0';
  }

  rep(i, 0, N-100) {
    while (ans[i] > 1) {
      ans[i] -= 2; ans[i+2]++; ans[i+3]++;
    }
  }

  for (sz = N/2; sz >= 0; sz--) {
    if (ans[sz]) break;
  }

  if (sz < 0) {
    printf("0\n");
    // continue;
    return 0;
  }

  for (; sz >= 0; sz--) {
    putchar('0'+ans[sz]);
  }
  putchar('\n');
  // }


  return 0;
}
