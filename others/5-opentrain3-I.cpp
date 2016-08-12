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
  for (LL i = (j); i < (k); i++)
typedef long long LL;
typedef long double LD;
typedef pair<LL, LL> PLL;
typedef pair<LL, LL> PII;
typedef pair<LD, LD> PDD;
typedef vector<LD> VD;
typedef vector<LD, LD> VDD;
typedef vector< vector<LD, LD> > VVD;
typedef vector<LL> VL;
typedef vector<LL, LL> VLL;
typedef vector< vector<LL, LL> > VVL;
typedef vector<LL> VI;
typedef vector<LL, LL> VII;
typedef vector< vector<LL, LL> > VVI;

#define N 4000000
#define MOD (1000000000+2015)

LL ns[N], ps[N], pl, nl;
LL dist[N];
LL ans[N];
LL c[N], c2[N];

void update2(LL k) {
  while (k < N) {
    c2[k] += 1;
    c2[k] %= MOD;
    k += k&-k;
  }
}

LL query2(LL k) {
  LL ret = 0;
  while (k) {
    ret += c2[k] % MOD;
    k -= k&-k;
  }
  return ret;
}


void update(LL k, LL v) {
  if (k == 0) return;
  while (k < N) {
    c[k] += v;
    c[k] %= MOD;
    k += k&-k;
  }
}

LL query(LL k) {
  LL ret = 0;
  while (k) {
    ret += c[k] % MOD;
    k -= k&-k;
  }
  return ret;
}

LL calc(LL n) {
  return n*(n+1)/2%MOD;
}

int main() {

  LL r; cin >> r;
  for (LL i = -r; i <= r; i++) {
    ps[pl++] = sqrt(r*r - i*i);
  }
  nl = pl-1;
  rep(i, 0, nl) {
    ns[i] = min(ps[i], ps[i+1]);
    ns[i] *= 2;
  }


  rep(i, 1, nl) {
    LL cur = calc(ns[i]);
    LL q1 = query2(N-ns[i]-1)+1, q2 = query(ns[i]);
    ans[i] = (cur*q1+q2) % MOD;
    update(ns[i], cur);
    update2(N-ns[i]);
  }

  LL res = 0;
  rep(i, 0, nl) {
    res += ans[i];
    res %= MOD;
  }

  cout << res << endl;

  return 0;
}
