#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

typedef long long LL;

struct Letter {
    LL c, d;
    void in() {
        int MM, mm, hh, dd;
        scanf("%lld %d.%d %d:%d", &c, &dd, &MM, &hh, &mm);
        d = mm + 63 * (hh + 29 * (dd + 31 * MM));
    }
};

const int N = 100030;
int n;
vector<LL> ts;
Letter ls[N];

int get(LL t) { return lower_bound(begin(ts), end(ts), t) - begin(ts) + 1; }

struct Node {
    LL setv, addv;
    LL maxv, minv, sumv;
};
struct SegTree {
    Node a[N * 4];
    int L, R;
    int QL, QR;
    LL sumtr, mintr, maxtr;
    LL val;

    void pushdown(int id) {
        int lc = id * 2, rc = id * 2 + 1;
        if (a[id].setv >= 0) {
            a[lc].addv = a[rc].addv = 0;
            a[lc].setv = a[rc].setv = a[id].setv;
            a[id].setv = -1;
        }
        if (a[id].addv) {
            a[lc].addv += a[id].addv;
            a[rc].addv += a[id].addv;
            a[id].addv = 0;
        }
    }

    void maintain(int id, int l, int r) {
        if (l != r) {
            int lc = id * 2, rc = id * 2 + 1;
            a[id].sumv = a[lc].sumv + a[rc].sumv;
            a[id].minv = min(a[lc].minv, a[rc].minv);
            a[id].maxv = max(a[lc].maxv, a[rc].maxv);
        }

        if (a[id].setv >= 0) {
            a[id].sumv = (r - l + 1) * a[id].setv;
            a[id].minv = a[id].maxv = a[id].setv;
        }
        if (a[id].addv) {
            a[id].sumv += (r - l + 1) * a[id].addv;
            a[id].minv += a[id].addv;
            a[id].maxv += a[id].addv;
        }

        if (l == r) {
            a[id].addv = 0;
            a[id].setv = -1;
        }
    }

    void _build(int id, int l, int r) {
        a[id].setv = -1;
        a[id].minv = a[id].maxv = a[id].sumv = 0;
        if (l == r) {
            a[id].minv = a[id].maxv = a[id].sumv = 0;
        } else {
            int m = (l + r) / 2;
            _build(id * 2, l, m);
            _build(id * 2, m + 1, r);
            maintain(id, l, r);
        }
    }
    void build(int l, int r) {
        L = l, R = r;
        _build(1, L, R);
    }

    void _add(int id, int l, int r) {
        if (QL <= l && r <= QR) {
            a[id].addv += val;
            // printf("[%d %d] of [%d %d] added by %lld\n", l, r, QL, QR, val);
        } else {
            pushdown(id);
            int m = (l + r) / 2;
            int lc = id * 2, rc = id * 2 + 1;
            if (QL <= m)
                _add(lc, l, m);
            else
                maintain(lc, l, m);

            if (m + 1 <= QR)
                _add(rc, m + 1, r);
            else
                maintain(rc, m + 1, r);
        }
        maintain(id, l, r);
    }
    void add(int l, int r, LL _val) {
        QL = l, QR = r, val = _val;
        _add(1, L, R);
    }

    void _set(int id, int l, int r) {
        if (QL <= l && r <= QR) {
            a[id].addv = 0;
            a[id].setv = val;
            // printf("[%d %d] of [%d %d] set to %lld\n", l, r, QL, QR, val);
        } else {
            pushdown(id);
            int m = (l + r) / 2;
            int lc = id * 2, rc = id * 2 + 1;
            if (QL <= m)
                _set(lc, l, m);
            else
                maintain(lc, l, m);

            if (m + 1 <= QR)
                _set(rc, m + 1, r);
            else
                maintain(rc, m + 1, r);
        }
        maintain(id, l, r);
    }
    void set(int l, int r, LL _val) {
        QL = l, QR = r, val = _val;
        _set(1, L, R);
    }

    void _query(int id, int l, int r) {
        maintain(id, l, r);
        if (QL <= l && r <= QR) {
            // printf("[%d %d] of [%d %d] queried, sum=%lld\n", l, r, QL, QR,
            //        a[id].sumv);
            sumtr += a[id].sumv;
            mintr = min(mintr, a[id].minv);
            maxtr = max(maxtr, a[id].maxv);
        } else {
            pushdown(id);
            int m = (l + r) / 2;
            int lc = id * 2, rc = id * 2 + 1;
            if (QL <= m)
                _query(lc, l, m);
            else
                maintain(lc, l, m);

            if (m + 1 <= QR)
                _query(rc, m + 1, r);
            else
                maintain(rc, m + 1, r);
        }
    }
    void query(int l, int r) {
        QL = l, QR = r;
        sumtr = 0;
        mintr = 1e18 + 1;
        maxtr = -1;
        _query(1, L, R);
        // printf("sum of [%d %d] is %lld\n", QL, QR, sumtr);
    }
} tree;

int main() {
#ifdef D
    freopen("c.in", "r", stdin);
#endif
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        ls[i].in();
        ts.push_back(ls[i].d);
    }

    sort(begin(ts), end(ts));
    ts.erase(unique(begin(ts), end(ts)), end(ts));

    tree.build(1, N);

    for (int i = 0; i < n; i++) {
        int kth = get(ls[i].d);
        tree.add(kth, N, ls[i].c);
        tree.query(1, N);
        LL cur = tree.mintr;
        if (cur > 0) cur = 0;
        printf("%lld\n", cur);
    }

    return 0;
}
