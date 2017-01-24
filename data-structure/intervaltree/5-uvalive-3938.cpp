#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

typedef long long LL;
typedef pair<int, int> Interval;

const int N = 500030;

int n, m;
LL prefix_sum[N];

LL sum(int l, int r) { return prefix_sum[r] - prefix_sum[l - 1]; }
LL sum(Interval p) { return sum(p.first, p.second); }

Interval better(Interval a, Interval b) {
    LL sum_a = sum(a), sum_b = sum(b);
    if (sum_a != sum_b) {
        return sum_a > sum_b ? a : b;
    }
    return a < b ? a : b;
}

struct IntervalTree {
    int max_prefix[4 * N];
    int max_suffix[4 * N];
    Interval max_sub[4 * N];

    int QL, QR;

    void pullup(int id, int l, int r) {
        int lc = id * 2, rc = id * 2 + 1;
        LL v1 = sum(l, max_prefix[lc]);
        LL v2 = sum(l, max_prefix[rc]);
        if (v1 == v2)
            max_prefix[id] = min(max_prefix[lc], max_prefix[rc]);
        else
            max_prefix[id] = v1 > v2 ? max_prefix[lc] : max_prefix[rc];

        v1 = sum(max_suffix[lc], r);
        v2 = sum(max_suffix[rc], r);
        if (v1 == v2)
            max_suffix[id] = min(max_suffix[lc], max_suffix[rc]);
        else
            max_suffix[id] = v1 > v2 ? max_suffix[lc] : max_suffix[rc];

        max_sub[id] = better(max_sub[lc], max_sub[rc]);
        max_sub[id] = better(max_sub[id], {max_suffix[lc], max_prefix[rc]});
    }

    void build(int id, int l, int r) {
        if (l == r) {
            max_prefix[id] = max_suffix[id] = l;
            max_sub[id] = {l, r};
        } else {
            int m = l + (r - l) / 2;
            int lc = id * 2, rc = id * 2 + 1;
            build(lc, l, m);
            build(rc, m + 1, r);
            pullup(id, l, r);
        }
    }

    Interval query_prefix(int id, int l, int r) {
        if (max_prefix[id] <= QR) return {l, max_prefix[id]};
        int m = l + (r - l) / 2;
        int lc = id * 2, rc = id * 2 + 1;
        if (QR <= m) return query_prefix(lc, l, m);
        Interval t = query_prefix(rc, m + 1, r);
        t.first = l;
        return better(t, {l, max_prefix[lc]});
    }

    Interval query_suffix(int id, int l, int r) {
        if (max_suffix[id] >= QL) return {max_suffix[id], r};
        int m = l + (r - l) / 2;
        int lc = id * 2, rc = id * 2 + 1;
        if (QL > m) return query_suffix(rc, m + 1, r);
        Interval t = query_suffix(lc, l, m);
        t.second = r;
        return better(t, {max_suffix[rc], r});
    }

    Interval query(int id, int l, int r) {
        if (QL <= l && r <= QR) return max_sub[id];
        int m = l + (r - l) / 2;
        int lc = id * 2, rc = id * 2 + 1;
        if (QR <= m) return query(lc, l, m);
        if (QL > m) return query(rc, m + 1, r);
        Interval i1 = query_prefix(rc, m + 1, r);
        Interval i2 = query_suffix(lc, l, m);
        Interval i3 = better(query(lc, l, m), query(rc, m + 1, r));
        return better(i3, {i2.first, i1.second});
    }

    void clean() {
        memset(max_prefix, 0, sizeof(max_prefix));
        memset(max_suffix, 0, sizeof(max_prefix));
        memset(max_sub, 0, sizeof(max_prefix));
    }
};

IntervalTree tree;

int main() {
#ifdef D
    freopen("3938.in", "r", stdin);
#endif
    int kase = 0;
    while (scanf("%d%d", &n, &m) != EOF) {
        memset(prefix_sum, 0, sizeof(prefix_sum));
        tree.clean();
        for (int i = 1; i <= n; i++) {
            LL t;
            scanf("%lld", &t);
            prefix_sum[i] = prefix_sum[i - 1] + t;
        }
        tree.build(1, 1, n);
        printf("Case %d:\n", ++kase);
        while (m--) {
            int l, r;
            scanf("%d%d", &l, &r);
            tree.QL = l;
            tree.QR = r;
            Interval ans = tree.query(1, 1, n);
            printf("%d %d\n", ans.first, ans.second);
        }
    }

    return 0;
}
