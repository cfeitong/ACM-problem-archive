#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

typedef long long LL;

struct F {
    LL p, d;
};

vector<F> fs;

typedef vector<F>::iterator Iter;

typedef pair<LL, LL> Stat;

pair<Stat, Stat> move(Iter st, Iter ed, Stat s) {
    sort(st, ed + 1, [](F a, F b) { return a.p < b.p; });
    LL cp = s.first;
    LL len = abs(st->p - ed->p);
    LL water = ed - st + 1;
    return {{st->p, s.second + abs(cp - ed->p) + len + water},
            {ed->p, s.second + abs(cp - st->p) + len + water}};
}

pair<Stat, Stat> merge(pair<Stat, Stat> a, pair<Stat, Stat> b) {
    LL p1 = a.first.first, c1 = a.first.second;
    LL p2 = a.second.first, c2 = a.second.second;
    LL c3 = b.first.second;
    LL c4 = b.second.second;
    return {{p1, min(c1, c3)}, {p2, min(c2, c4)}};
}

int main() {
#ifdef D
    freopen("k.in", "r", stdin);
#endif
    LL n;
    scanf("%lld", &n);
    for (LL i = 1; i <= n; i++) {
        LL t;
        scanf("%lld", &t);
        fs.push_back({i, t});
    }
    sort(begin(fs), end(fs), [](F a, F b) { return a.d < b.d; });
    auto st = begin(fs);
    auto ed = st;
    Stat c1{0, -1}, c2{0, -1};
    pair<Stat, Stat> c{c1, c2};
    while (st != end(fs)) {
        while (ed != end(fs) && ed->d == st->d) ed++;
        auto a = move(st, ed - 1, c.first);
        auto b = move(st, ed - 1, c.second);
        c = merge(a, b);
        // printf("(%lld,%lld),(%lld,%lld)\n", c.first.first, c.first.second,
        //        c.second.first, c.second.second);
        st = ed;
    }

    printf("%lld\n", min(c.first.second, c.second.second));

    return 0;
}
