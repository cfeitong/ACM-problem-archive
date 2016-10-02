
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

struct T {
    int t; string s; string pa;
    bool operator < (const T o) const {
        if (t == o.t) {
            if (s == o.s) {
                return pa < o.pa;
            }
            else {
                return s < o.s;
            }
        }
        else {
            return t < o.t;
        }
    }
    bool operator == (const T o) const {
        return t == o.t && s == o.s && pa == o.pa;
    }
};

vector< vector<T> > book;
vector<T> numed;
bool isbook[N];
vector<T> son[N];

vector<T> split(string s) {
    int cur = 0;
    vector<T> ret;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '/') {
            if (ret.empty()) {
                ret.pb({0,s.substr(cur, i-cur), ""});
            }
            else {
                ret.pb({0,s.substr(cur, i-cur), ret.back().s});
            }
            cur = i+1;
        }
    }
    if (ret.empty()) {
        ret.pb({1,s.substr(cur, s.size()-cur), ""});
    }
    else {
        ret.pb({1,s.substr(cur, s.size()-cur), ret.back().s});
    }
    return ret;
}

int getid(T s) {
    return lower_bound(numed.begin()+1, numed.end(), s) - numed.begin();
}

void build() {
    for (auto it : book) {
        son[0].pb(it[0]);
        for (int i = 0; i < it.size()-1; i++) {
            int id1 = getid(it[i]);
            son[id1].pb(it[i+1]);
        }
    }

    for (int i = 0; i < N; i++) {
        sort(all(son[i]));
        auto ed = unique(all(son[i]));
        son[i].erase(ed, son[i].end());
    }
}

void numberbook() {
    numed.pb({0,"", ""});
    for (auto it : book) {
        for (auto it1: it) {
            numed.pb(it1);
        }
    }
    sort(numed.begin()+1, numed.end());
    auto ed = unique(numed.begin()+1, numed.end());
    numed.erase(ed, numed.end());
}

void findbook() {
    for (auto it1 : book) {
        isbook[getid(it1.back())] = 1;
    }
}

void init() {
    book.clear();
    numed.clear();
    memset(isbook, 0, sizeof(isbook));
    for (int i = 0; i < N; i++) {
        son[i].clear();
    }
}

void print(int id, int lv) {
    for (int i = 0; i < lv; i++) cout << "    ";
    cout << numed[id].s << endl;

    if (!isbook[id]) {
        for (auto it : son[id]) {
            print(getid(it), lv+1);
        }
    }

}

int main() {
    freopen("a.in", "r", stdin);
    int kase = 0;
    while (1) {
        init();
        kase++;
        string tmp;
        if (!getline(cin, tmp)) {
            break;
        }
        book.pb(split(tmp));
        while (1) {
            getline(cin, tmp);
            if (tmp.size() == 1 && tmp[0] == '0') break;
            book.pb(split(tmp));
        }

        sort(all(book));
        auto ed = unique(all(book));
        book.erase(ed, book.end());

        numberbook();
        findbook();
        build();

        cout << "Case " << kase << ":";
        print(0,-1);

        // for (auto it : book) {
        //     for (auto k : it) {
        //         cout << k << '/';
        //     }
        //     cout << endl;
        // }

    }
    return 0;
}
