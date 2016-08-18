/*
  ID: cfeiton1
  PROG: msquare
  LANG: C++11
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <list>
#include <algorithm>
#include <string>
#include <stack>
#include <deque>
#include <string>
using namespace std;

map<vector<int>, string> mp;
typedef vector<int>::iterator Iter;

vector<int> init{1,2,3,4,5,6,7,8};
vector<int> tar;

void rrot(Iter s, Iter e) {
  int t = *e;
  while (s < e) {
    *e = *(e-1);
    e--;
  }
  *s = t;
}

void lrot(Iter s, Iter e) {
  int t = *s;
  while (s < e) {
    *s = *(s+1);
    s++;
  }
  *e = t;
}

string bfs() {
  queue<vector<int> > q;
  q.push(init);
  while (!q.empty()) {
    auto cur = q.front(); q.pop();
    if (cur == tar) return mp[cur];
    vector<int> tmp = cur;

    tmp = cur;
    for (int i = 0; i < 4; i++) swap(tmp[i], tmp[7-i]);
    if (mp.find(tmp) == mp.end() || mp[tmp].size() > mp[cur].size()+1) {
      mp[tmp] = mp[cur] + "A";
      q.push(tmp);
    }

    tmp = cur;
    rrot(tmp.begin(), tmp.begin()+3);
    lrot(tmp.begin()+4, tmp.end()-1);
    if (mp.find(tmp) == mp.end() || mp[tmp].size() > mp[cur].size()+1) {
      mp[tmp] = mp[cur] + "B";
      q.push(tmp);
    }

    tmp = cur;
    int t = tmp[1];
    tmp[1] = tmp[6];
    tmp[6] = tmp[5];
    tmp[5] = tmp[2];
    tmp[2] = t;
    if (mp.find(tmp) == mp.end() || mp[tmp].size() > mp[cur].size()+1) {
      mp[tmp] = mp[cur] + "C";
      q.push(tmp);
    }


  }
}

int main() {
  freopen("msquare.in", "r", stdin);
#ifndef DEBUG
  freopen("msquare.out", "w", stdout);
#endif

  for (int i = 0; i < 8; i++) {
    int t;
    scanf("%d", &t); tar.push_back(t);
  }

  mp[init] = "";

  string ans = bfs();
  cout << ans.size() << endl;
  cout << ans << endl;

  // auto tmp = init;
  // for (auto op : ans) {
  //   if (op == 'A') {
  //     for (int i = 0; i < 4; i++) swap(tmp[i], tmp[7-i]);
  //   }
  //   else if (op == 'B') {
  //     rrot(tmp.begin(), tmp.begin()+3);
  //     lrot(tmp.begin()+4, tmp.end()-1);
  //   }
  //   else {
  //     int t = tmp[1];
  //     tmp[1] = tmp[6];
  //     tmp[6] = tmp[5];
  //     tmp[5] = tmp[2];
  //     tmp[2] = t;
  //   }
  //   for (int i = 0; i < 4; i++) printf("%d", tmp[i]);
  //   puts("");
  //   for (int i = 0; i < 4; i++) printf("%d", tmp[7-i]);
  //   puts("");
  //   puts("");
  // }

  return 0;
}
