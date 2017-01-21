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
#define all(c) c.begin(), c.end()
#define rep(i, j, k)                            \
  for (int i = (j); i < (k); i++)
typedef  long long LL;
typedef long double LD;
typedef pair<LL, LL> PLL;
typedef  pair<int, int> PII;
typedef pair<LD, LD> PDD;

#define N 103000


class ThreeIncreasing {
public:
  int minEaten(int a, int b, int c) {
      if (c <= 2 || b == 1) {
          return -1;
      }
      int ans = 0;
      ans += max(0, b-c+1);
      b = min(b, c-1);
      ans += max(0, a-b+1);
      return ans;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 15; int Arg1 = 40; int Arg2 = 22; int Arg3 = 19; verify_case(0, Arg3, minEaten(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 5; int Arg1 = 6; int Arg2 = 6; int Arg3 = 2; verify_case(1, Arg3, minEaten(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 6; int Arg1 = 1; int Arg2 = 3000; int Arg3 = -1; verify_case(2, Arg3, minEaten(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 6; int Arg1 = 4; int Arg2 = 2; int Arg3 = -1; verify_case(3, Arg3, minEaten(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 4; int Arg1 = 2; int Arg2 = 6; int Arg3 = 3; verify_case(4, Arg3, minEaten(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arg0 = 1; int Arg1 = 1234; int Arg2 = 3000; int Arg3 = 0; verify_case(5, Arg3, minEaten(Arg0, Arg1, Arg2)); }
	void test_case_6() { int Arg0 = 2789; int Arg1 = 2400; int Arg2 = 1693; int Arg3 = 1806; verify_case(6, Arg3, minEaten(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
  ThreeIncreasing ___test;
  ___test.run_test(-1);
}
// END CUT HERE
