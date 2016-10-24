/*
  ID: cfeiton1
  PROG: camelot
  LANG: C++11
*/

#include <functional>
#include <tuple>
#include <cassert>
#include <numeric>
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
#include <climits>
#include <complex>
using namespace std;

#define pb push_back
#define pf push_front
#define mp make_pair
#define mt make_tuple
#define INF 0xf3f3f
#define F first
#define S second
#define speedup ios_base::sync_with_stdio(0);cin.tie(0)
#define all(c) c.begin(), c.end()
#define rep(i, j, k) for (int i = (j); i < (int)(k); i++)
#define rep2(i,j, f1,t1, f2,t2) for (int i = (f1); i < (int)(t1); i++) for (int j = (f2); j < (int)(t2); j++)
#define Rep(i, j, k) for (int i = (j); i <= (int)(k); i++)
#define Rep2(i,j, f1,t1, f2,t2) for (int i = (f1); i <= (int)(t1); i++) for (int j = (f2); j <= (int)(t2); j++)
#define per(i, j, k) for (int i = (j); i >= (int)(k); i--)
typedef long long             LL;
typedef long double           LD;
typedef pair<LL, LL>          PLL;
typedef pair<int, int>        PII;
typedef pair<LD, LD>          PDD;
typedef vector<LD>            VD;
typedef vector<PDD>           VDD;
typedef vector< vector<PDD> > VVD;
typedef vector<LL>            VL;
typedef vector<PLL>           VLL;
typedef vector< vector<PLL> > VVL;
typedef vector<int>           VI;
typedef vector<PII>           VII;
typedef vector<vector<PII> >  VVI;

bool in(LD       &v) {return scanf("%Lf",  &v)!=EOF;}
bool in(LL       &v) {return scanf("%lld", &v)!=EOF;}
bool in(int      &v) {return scanf("%d",   &v)!=EOF;}
bool in(char     *v) {return scanf("%s",    v)!=EOF;}
bool in(char     &v) {return scanf("%c",   &v)!=EOF;}
bool in(unsigned &v) {return scanf("%u",   &v)!=EOF;}
bool in(string   &v) {return (bool)(cin >> v);}
template<typename T, typename... Args> bool in(T &v, Args &...args) {bool ret = in(v); return ret && in(args...);}

void out(LD       v) {printf("%Lf",  v);}
void out(LL       v) {printf("%lld", v);}
void out(int      v) {printf("%d",   v);}
void out(char     v) {printf("%c",    v);}
void out(unsigned v) {printf("%u",   v);}
void out(string   v) {printf("%s",    v.c_str());}
template<typename T> void out(vector<T> &v) {for (int i = 0; i < (int)v.size(); i++) out(v[i]);}
template<typename T, typename... Args> void out(T v, Args ...args) {out(v); out(args...);}

int r, c;
int kr, kc;
int ans = INF;
VI pos, meet_pos;

int b[1000];
int dist[1000][1000];

int en(int y, int x) {
    return y * 31 + x;
}
void ex(int &y, int &x, int v) {
    y = v / 31;
    x = v % 31;
}

VI very(VI ori) {
    VI ret;
    for (auto it : ori) {
        int y,x; ex(y,x,it);
        if (1 <= y && y <= r &&
            1 <= x && x <= c) ret.pb(it);
    }
    return ret;
}

VI move(int k) {
    int y,x; ex(y,x,k);
    VI ret;
    ret.pb(en(y-2,x-1));
    ret.pb(en(y-2,x+1));
    ret.pb(en(y+2,x-1));
    ret.pb(en(y+2,x+1));
    ret.pb(en(y-1,x-2));
    ret.pb(en(y-1,x+2));
    ret.pb(en(y+1,x-2));
    ret.pb(en(y+1,x+2));
    ret = very(ret);
    return ret;
}

void bfs(int k) {
    queue<int> q;
    q.push(k);
    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        auto nxt = move(cur);
        for (auto it : nxt) {
            if (!dist[k][it] && it != k) {
                dist[k][it] = dist[k][cur]+1;
                q.push(it);
            }
        }
    }
    rep(i,0,1000) {
        if (!dist[k][i] && i != k) dist[k][i] = INF;
    }
}

int d_f(int f, int t) {
    int x1,x2,y1,y2;
    ex(y1,x1,f); ex(y2,x2,t);
    return max(abs(x1-x2),abs(y1-y2));
}


int main() {
  freopen("camelot.in", "r", stdin);
#ifndef DEBUG
  freopen("camelot.out", "w", stdout);
#endif
  in(r, c);
  char t1[3];
  in(t1, kr);
  kc = t1[0]-'A'+1;
  int t2;
  while (in(t1,t2)) pos.pb(en(t2,t1[0]-'A'+1));
  Rep(i,1,r) Rep(j,1,c) {
      bfs(en(i,j));
  }

  meet_pos.pb(en(kr,kc));
  Rep(i,1,3) {
      meet_pos.pb(en(kr, kc-i));
      meet_pos.pb(en(kr+i, kc));
      meet_pos.pb(en(kr, kc+i));
      meet_pos.pb(en(kr-i, kc));
      meet_pos.pb(en(kr+i, kc-i));
      meet_pos.pb(en(kr+i, kc+i));
      meet_pos.pb(en(kr-i, kc+i));
      meet_pos.pb(en(kr-i, kc-i));
  }
  meet_pos = very(meet_pos);

  Rep(i,1,r) Rep(j,1,c) {
      int end_p = en(i,j);

      int sum = 0;
      for (auto it : pos) {
          sum += dist[it][end_p];
      }
      int tmp = abs(i-kr)+abs(j-kc) + sum;
      ans = min(ans, tmp);

      for (auto k_p : pos) {
          int tmp = sum;
          tmp -= dist[k_p][end_p];
          for (auto m_p : meet_pos) {
              tmp += d_f(m_p, en(kr,kc));
              tmp += dist[k_p][m_p] + dist[m_p][end_p];
              ans = min(ans, tmp);
              tmp -= d_f(m_p, en(kr,kc));
              tmp -= dist[k_p][m_p] + dist[m_p][end_p];
          }
      }
  }

  out(ans,'\n');

  return 0;
}
