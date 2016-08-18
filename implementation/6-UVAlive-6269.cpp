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
#define N 103

int n;
int bone[11];
PII fail = {-1,-1};

int get_nth_bone(vector<int> v) {
  int ret = 0;
  for (auto it : v) {
    ret |= (1 << it);
  }
  return ret;
}

void init() {
  bone[0] = get_nth_bone({0,1,2,3,4,5});
  bone[1] = get_nth_bone({1,2});
  bone[2] = get_nth_bone({0,1,3,4,6});
  bone[3] = get_nth_bone({0,1,2,3,6});
  bone[4] = get_nth_bone({1,2,5,6});
  bone[5] = get_nth_bone({0,5,6,2,3});
  bone[6] = get_nth_bone({0,5,6,2,3,4});
  bone[7] = get_nth_bone({0,1,2});
  bone[8] = get_nth_bone({0,1,2,3,4,5,6});
  bone[9] = get_nth_bone({0,1,2,3,5,6});
}

int nbit(int k, int n) {
  return k & (1 << n);
}

PII nextm(PII cur) {
  PII ret = {cur.F, cur.S+1};
  if (ret.S == 60) {
    ret.S = 00;
    ret.F++;
  }
  if (ret.F == 24) {
    ret.F = 0;
  }
  return ret;
}

PII issub(int ori, int cur) {
  int broken = 0;
  int right = 0;
  ori = bone[ori]; cur = bone[cur];
  rep(i, 0, 10) {
    if (nbit(ori, i) && nbit(cur, i)) {
      right |= (1 << i);
    }
    else if (nbit(ori, i)) {
      broken |= (1 << i);
    }
    else if (nbit(cur, i)) return fail;
  }
  return {broken, right};
}

VII ans;
VII seq;

bool check(int h, int m) {
  int b0=0, r0=0, b1=0, r1=0;
  int b2=0, r2=0, b3=0, r3=0;
  rep(i, 0, n) {
    int c0 = h / 10, n0 = seq[i].F/10;
    int c1 = h % 10, n1 = seq[i].F%10;
    int c2 = m / 10, n2 = seq[i].S/10;
    int c3 = m % 10, n3 = seq[i].S%10;

    auto t0 = issub(c0, n0);
    auto t1 = issub(c1, n1);
    auto t2 = issub(c2, n2);
    auto t3 = issub(c3, n3);

    if (t0 == fail || t2 == fail || t3 == fail || t1 == fail) return 0;

    b0 |= t0.F; r0 |= t0.S;
    b1 |= t1.F; r1 |= t1.S;
    b2 |= t2.F; r2 |= t2.S;
    b3 |= t3.F; r3 |= t3.S;

    if (b0 & r0) return 0;
    if (b1 & r1) return 0;
    if (b2 & r2) return 0;
    if (b3 & r3) return 0;

    auto newt = nextm({h,m});
    h = newt.F, m = newt.S;
  }
  return 1;
}

int main() {
  freopen("d.in", "r", stdin);

  init();

  while (in_i(n) != EOF) {
    ans.clear();
    seq.clear();
    rep(i, 0, n) {
      int h, m; scanf("%d:%d", &h, &m);
      seq.pb({h,m});
    }

    rep2(h, m, 0, 24, 0, 60) {
      if (check(h, m)) {
        ans.pb({h,m});
      }
    }

    sort(all(ans), [](PII a, PII b) {
        if (a.F == b.F) {
          return a.S < b.S;
        }
        return a.F < b.F;
      });

    if (ans.empty()) puts("none");
    else {
      rep(i, 0, ans.size()) {
        auto it = ans[i];
        printf("%02d:%02d%c", it.F, it.S, " \n"[i==ans.size()-1]);
      }
    }

  }

  return 0;
}
