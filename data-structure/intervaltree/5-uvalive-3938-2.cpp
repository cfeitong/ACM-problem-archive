#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long LL;

const int N = 500020 * 4;

int n, m;
LL presum[N];

struct Seg {
    int l, r;
    bool operator<(const Seg& o) const {
        if (l == o.l) return r < o.r;
        return l < o.l;
    }
};

struct Node {
    int id, l, r;
    int pre, suf;
    Seg sub;
};

LL sum(Seg a) { return presum[a.r] - presum[a.l - 1]; }

Seg better(Seg a, Seg b) {
    LL s1 = sum(a), s2 = sum(b);
    if (s1 == s2) return a < b ? a : b;
    return s1 > s2 ? a : b;
}

Node maintain(Node a, Node b) {
    Node ret;
    ret.l = a.l;
    ret.r = b.r;
    ret.pre = better({a.l, a.pre}, {a.l, b.pre}).r;
    ret.suf = better({a.suf, b.r}, {b.suf, b.r}).l;
    ret.sub = better(better(a.sub, b.sub), {a.suf, b.pre});
    return ret;
}

struct SegTree {
    Node ns[N];
    int QL, QR;

    void build(int id, int l, int r) {
        int m = l + (r - l) / 2;
        int lc = id * 2, rc = id * 2 + 1;
        Node& c = ns[id];
        if (l == r) {
            c.pre = c.suf = l;
            c.sub = {l, r};
        } else {
            build(id * 2, l, m);
            build(id * 2 + 1, m + 1, r);
            c = maintain(ns[lc], ns[rc]);
        }
    }

    Node query(int id, int l, int r) {
        int m = l + (r - l) / 2;
        int lc = id * 2, rc = id * 2 + 1;
        if (QL <= l && r <= QR) return ns[id];
        if (QR <= m) return query(lc, l, m);
        if (m + 1 <= QL) return query(rc, m + 1, r);
        return maintain(query(lc, l, m), query(rc, m + 1, r));
    }

    void clean() { memset(ns, 0, sizeof(ns)); }
};

SegTree tree;

int main() {
#ifdef D
    freopen("3938.in", "r", stdin);
#endif
    int kase = 0;
    while (scanf("%d%d", &n, &m) != EOF) {
        presum[0] = 0;
        tree.clean();
        printf("Case %d:\n", ++kase);
        for (int i = 1; i <= n; i++) {
            LL t;
            scanf("%lld", &t);
            presum[i] = presum[i - 1] + t;
        }
        tree.build(1, 1, n);
        for (int i = 0; i < m; i++) {
            scanf("%d%d", &tree.QL, &tree.QR);
            Node ans = tree.query(1, 1, n);
            printf("%d %d\n", ans.sub.l, ans.sub.r);
        }
    }

    return 0;
}
