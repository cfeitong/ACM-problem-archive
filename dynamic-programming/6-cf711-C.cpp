

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
#define out_d(a) printf("%.10Lf\n", a);
#define out_d2(a,b) printf("%.10Lf %.10Lf\n", a, b);
#define out_d3(a,b,c) printf("%.10Lf %.10Lf %.10Lf\n", a, b, c);
#define out_d4(a,b,c,d) printf("%.10Lf %.10Lf %.10Lf %.10Lf\n", a, b, c, d);
#define out_s(s) printf("%s\n", s);
#define out_ci(c) if (!c.empty()) printf("%d", c[0]); rep(i, 1, c.size()) printf(" %d", c[i]); puts("")
#define out_cd(c) if (!c.empty()) printf("%.10Lf", c[0]); rep(i, 1, c.size()) printf(" %.10Lf", c[i]); puts("")
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
#define N 203

int n,m,k;
LL c[N];
LL p[N][N];

LL dp[N][N][N];

int main() {
  freopen("c.in", "r", stdin);
  // speedup;
  cin >> n >> m >> k;
  rep(i, 0, n) cin >> c[i];
  rep2(i,j, 0,n, 1,m+1) {
    cin >> p[i][j];
  }

  rep(i,0,N) rep(j,0,N) rep(l,0,N) dp[i][j][l] = 0x3f3f3f3f3f3f3f3f;

  if (!c[0])
    Rep(i,1,m)
      dp[0][1][i] = p[0][i];
  else
    dp[0][1][c[0]] = 0;

  rep(i, 1, n) {
    Rep(ki, 1, k) {
      Rep(pc, 1, m) {
        if (c[i]) {
          int co = c[i];
          if (dp[i-1][ki][pc] != -1) {
            if (co == pc) dp[i][ki][co] = min(dp[i][ki][co], dp[i-1][ki][pc]);
            else dp[i][ki+1][co] = min(dp[i][ki+1][co], dp[i-1][ki][pc]);
          }
        }
        else {
          Rep(co, 1, m) {
            if (dp[i-1][ki][pc] != -1) {
              if (co == pc) dp[i][ki][co] = min(dp[i][ki][co], dp[i-1][ki][pc]+p[i][co]);
              else dp[i][ki+1][co] = min(dp[i][ki+1][co], dp[i-1][ki][pc]+p[i][co]);
            }
          }
        }
      }
    }
  }

  LL ans = 0x3f3f3f3f3f3f3f3f;
  Rep(c, 1, m) {
      ans = min(ans, dp[n-1][k][c]);
  }
  cout << (ans == 0x3f3f3f3f3f3f3f3f ? -1 : ans) << endl;

  return 0;
}
