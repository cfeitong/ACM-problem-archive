
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
#define rep(i, j, k) for (LL i = (j); i < (LL)(k); i++)
#define rep2(i,j, f1,t1, f2,t2) for (LL i = (f1); i < (LL)(t1); i++) for (LL j = (f2); j < (LL)(t2); j++)
#define Rep(i, j, k) for (LL i = (j); i <= (LL)(k); i++)
#define Rep2(i,j, f1,t1, f2,t2) for (LL i = (f1); i <= (LL)(t1); i++) for (LL j = (f2); j <= (LL)(t2); j++)
#define per(i, j, k) for (LL i = (j); i >= (LL)(k); i--)
#define out_i(a) prLLf("%d\n", a);
#define out_i2(a,b) prLLf("%d %d\n", a, b);
#define out_i3(a,b,c) prLLf("%d %d %d\n", a, b, c);
#define out_i4(a,b,c,d) prLLf("%d %d %d %d\n", a, b, c, d);
#define out_l(a) prLLf("%lld\n", a);
#define out_l2(a,b) prLLf("%lld %lld\n", a, b);
#define out_l3(a,b,c) prLLf("%lld %lld %lld\n", a, b, c);
#define out_l4(a,b,c,d) prLLf("%lld %lld %lld %lld\n", a, b, c, d);
#define out_d(a) prLLf("%.10Lf\n", a);
#define out_d2(a,b) prLLf("%.10Lf %.10Lf\n", a, b);
#define out_d3(a,b,c) prLLf("%.10Lf %.10Lf %.10Lf\n", a, b, c);
#define out_d4(a,b,c,d) prLLf("%.10Lf %.10Lf %.10Lf %.10Lf\n", a, b, c, d);
#define out_s(s) prLLf("%s\n", s);
#define out_ci(c) if (!c.empty()) prLLf("%d", c[0]); rep(i, 1, c.size()) prLLf(" %d", c[i]); puts("")
#define out_cd(c) if (!c.empty()) prLLf("%.10Lf", c[0]); rep(i, 1, c.size()) prLLf(" %.10Lf", c[i]); puts("")
#define out_cl(c) if (!c.empty()) prLLf("%lld", c[0]); rep(i, 1, c.size()) prLLf(" %lld", c[i]); puts("")
typedef long long LL;
typedef long double LD;
typedef pair<LL, LL> PLL;
typedef pair<LL, LL> PII;
typedef pair<LD, LD> PDD;
typedef vector<LD> VD;
typedef vector<PDD> VDD;
typedef vector< vector<PDD> > VVD;
typedef vector<LL> VL;
typedef vector<PLL> VLL;
typedef vector< vector<PLL> > VVL;
typedef vector<LL> VI;
typedef vector<PII> VII;
typedef vector<vector<PII> > VVI;
// #define N 100000
// UVa12298 Super Poker II
// Rujia Liu
#include <complex>
#include <cmath>
#include <vector>
using namespace std;

const LD PI = 3.1415926535897932384626433832795028841971693993L;

typedef complex<LD> CD;

// Cooley-TukeyµÄFFTËã·¨£¬µü´úÊµÏÖ¡£inverse = falseÊ±¼ÆËãÄæFFT
inline void FFT(vector<CD> &a, bool inverse) {
  int n = a.size();
  // Ô­µØ¿ìËÙbit reversal
  for(int i = 0, j = 0; i < n; i++) {
    if(j > i) swap(a[i], a[j]);
    int k = n;
    while(j & (k >>= 1)) j &= ~k;
    j |= k;
  }

  LD pi = inverse ? -PI : PI;
  for(int step = 1; step < n; step <<= 1) {
    // °ÑÃ¿ÏàÁÚÁ½¸ö¡°stepµãDFT¡±Í¨¹ýÒ»ÏµÁÐºûµû²Ù×÷ºÏ²¢ÎªÒ»¸ö¡°2*stepµãDFT¡±
    LD alpha = pi / step;
    // ÎªÇó¸ßÐ§£¬ÎÒÃÇ²¢²»ÊÇÒÀ´ÎÖ´ÐÐ¸÷¸öÍêÕûµÄDFTºÏ²¢£¬¶øÊÇÃ¶¾ÙÏÂ±êk
    // ¶ÔÓÚÒ»¸öÏÂ±êk£¬Ö´ÐÐËùÓÐDFTºÏ²¢ÖÐ¸ÃÏÂ±ê¶ÔÓ¦µÄºûµû²Ù×÷£¬¼´Í¨¹ýE[k]ºÍO[k]¼ÆËãX[k]
    // ºûµû²Ù×÷²Î¿¼£ºhttp://en.wikipedia.org/wiki/Butterfly_diagram
    for(int k = 0; k < step; k++) {
      // ¼ÆËãomega^k. Õâ¸ö·½·¨Ð§ÂÊµÍ£¬µ«Èç¹ûÓÃÃ¿´Î³ËomegaµÄ·½·¨µÝÍÆ»áÓÐ¾«¶ÈÎÊÌâ¡£
      // ÓÐ¸ü¿ì¸ü¾«È·µÄµÝÍÆ·½·¨£¬ÎªÁËÇåÎúÆð¼ûÕâÀïÂÔÈ¥
      CD omegak = exp(CD(0, alpha*k)); 
      for(int Ek = k; Ek < n; Ek += step << 1) { // EkÊÇÄ³´ÎDFTºÏ²¢ÖÐE[k]ÔÚÔ­Ê¼ÐòÁÐÖÐµÄÏÂ±ê
        int Ok = Ek + step; // OkÊÇ¸ÃDFTºÏ²¢ÖÐO[k]ÔÚÔ­Ê¼ÐòÁÐÖÐµÄÏÂ±ê
        CD t = omegak * a[Ok]; // ºûµû²Ù×÷£ºx1 * omega^k
        a[Ok] = a[Ek] - t;  // ºûµû²Ù×÷£ºy1 = x0 - t
        a[Ek] += t;         // ºûµû²Ù×÷£ºy0 = x0 + t
      }
    }
  }

  if(inverse)
    for(int i = 0; i < n; i++) a[i] /= n;
}

// ÓÃFFTÊµÏÖµÄ¿ìËÙ¶àÏîÊ½³Ë·¨
inline vector<LD> operator * (const vector<LD>& v1, const vector<LD>& v2) {
  int s1 = v1.size(), s2 = v2.size(), S = 2;
  while(S < s1 + s2) S <<= 1;
  vector<CD> a(S,0), b(S,0); // °ÑFFTµÄÊäÈë³¤¶È²¹³É2µÄÃÝ£¬²»Ð¡ÓÚv1ºÍv2µÄ³¤¶ÈÖ®ºÍ
  for(int i = 0; i < s1; i++) a[i] = v1[i];
  FFT(a, false);
  for(int i = 0; i < s2; i++) b[i] = v2[i];
  FFT(b, false);
  for(int i = 0; i < S; i++) a[i] *= b[i];
  FFT(a, true);
  vector<LD> res(s1 + s2 - 1);
  for(int i = 0; i < s1 + s2 - 1; i++) res[i] = a[i].real(); // Ðé²¿¾ùÎª0
  return res;
}

int main() {
    // freopen("f.in", "r", stdin);
    int T; in_i(T);

    while (T--) {
        vector<LD> a, b;
        int n; in_i(n);
        LD sum = 0;
        rep(i,0,n) {
            LD t; in_d(t);
            b.pb(t);
            sum += t*t;
        }
        rep(i,0,n) {
            LD t; in_d(t);
            a.pb(t);
            sum += t*t;
        }
        for (int i = 0, j = b.size()-1; i < j; i++, j--) {
            swap(b[i], b[j]);
        }

        vector<LD> res = a*b;
        // vector<LL> res;
        // for (auto it : _res) {
        //     res.pb((LL)(it+0.5L));
        // }

        LD mi = 0;

        int k = -1;
        rep(i,0,n-1) {
            if (mi < res[i]+res[i+n]) {
                k = i;
                mi = res[i]+res[i+n];
            }
        }
        if (mi < res[n-1]) {
            k = n-1;
            mi = res[n-1];
        }


        for (int i = 0, j = b.size()-1; i < j; i++, j--) {
            swap(b[i], b[j]);
        }

        int d = k-n+1;
        LL ans = 0;
        rep(i,0,n) {
            LL tmp = a[(i+d+n)%n] - b[i];
            ans += tmp*tmp;
        }

        printf("%lld\n", ans);
        // printf("%Lf\n", sum - 2*mi);
    }

    return 0;
}
