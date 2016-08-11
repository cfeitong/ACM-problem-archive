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

#define N 200000

int n, k;
int pa[N];
int cnt[N];
map<PII, int> eid;
vector<int> edg[N];
vector<int> ans;

int build(int c) {
  cnt[c] = 1;
  for (auto &it : edg[c]) {
    if (it == pa[c]) {
      it = INF;
      continue;
    }
    pa[it] = c;
    cnt[c] += build(it);
  }
  sort(all(edg[c]));
  return cnt[c];
}

int dfs(int c) {
  if (edg[c].size() == 2) {
    int cut1 = dfs(edg[c][0]);
    if (cnt[c] - cut1 > k) {
      ans.pb(eid[mp(edg[c][0], c)]);
      cut1 = cnt[edg[c][0]];
    }

    return cut1;
  }
  else if (edg[c].size() == 3) {
    int cut1 = dfs(edg[c][0]);
    int cut2 = dfs(edg[c][1]);

    if (cnt[c] - cut1 - cut2 > k) {
      ans.pb(eid[mp(edg[c][1], c)]);
      cut2 = cnt[edg[c][1]];
    }
    if (cnt[c] - cut1 - cut2 > k) {
      ans.pb(eid[mp(edg[c][0], c)]);
      cut1 = cnt[edg[c][0]];
    }

    return cut1 + cut2;
  }
  return 0;
}

int main() {
  // freopen("j.in", "r", stdin);
  freopen("tree.in", "r", stdin);
  freopen("tree.out", "w", stdout);

  in_i2(n, k);

  rep(i, 1, n) {
    int a, b; in_i2(a, b);
    edg[a].pb(b); edg[b].pb(a);
    eid[mp(a,b)] = eid[mp(b,a)] = i;
  }

  pa[1] = 1;
  build(1);
  edg[1].pb(INF);

  dfs(1);

  int ex = (2*n)/k+(2*n%k!=0) - 1;
  if (ex < ans.size()) {
    printf("-1\n");
  }
  else {
    printf("%d\n", (int) ans.size());
    for (auto it : ans) {
      printf("%d ", it);
    }
    puts("");
  }


  return 0;
}
