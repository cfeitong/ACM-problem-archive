#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

typedef long long LL;

int n;
struct P {
    LL x, y, id;
    bool operator<(const P& rhs) const {
        return x == rhs.x ? y < rhs.y : x < rhs.x;
    }
};

LL area2(P a, P b, P c) {
    P ab{a.x - b.x, a.y - b.y, 0}, bc{b.x - c.x, b.y - c.y, 0};
    return abs(ab.x * bc.y - ab.y * bc.x);
}

bool check_line(const vector<P>& ps) {
    if (ps.size() < 3) return 1;
    for (int i = 0; i < (int)ps.size() - 2; i++) {
        if (area2(ps[i], ps[i + 1], ps[i + 2])) return 0;
    }
    return 1;
}

vector<P> ps;

int main() {
#ifdef D
    freopen("f.in", "r", stdin);
#endif
    while (~scanf("%d", &n)) {
        for (int i = 1; i <= n; i++) {
            int x, y;
            scanf("%d%d", &x, &y);
            ps.push_back({x, y, i});
        }

        auto line = ps;
        sort(begin(line), end(line));

        if (check_line(line)) {
            printf("%d\n", 1);
            printf("%lld ", line.front().id);
            printf("%lld\n", line.back().id);
        } else {
            puts("0");
        }
    }

    return 0;
}
