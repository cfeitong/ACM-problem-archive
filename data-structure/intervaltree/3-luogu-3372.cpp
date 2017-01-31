#include <cstdio>

using namespace std;

int n, m;

const int N = 1e6 + 5;

typedef long long LL;

LL arr[N];

struct Node {
    LL sumv;
    LL addv;
};

struct SegTree {
    Node a[4 * N];
    LL* arr;
    LL sumtr;
    int QL, QR;
    int L, R;

    void pushdown(int id) {
        int lc = id * 2, rc = id * 2 + 1;
        a[lc].addv += a[id].addv;
        a[rc].addv += a[id].addv;
        a[id].addv = 0;
    }

    void maintain(int id, int l, int r) {
        int lc = id * 2, rc = id * 2 + 1;
        if (l != r) {
            a[id].sumv = a[lc].sumv + a[rc].sumv;
        }
        a[id].sumv += a[id].addv * (r - l + 1);
        if (l == r) a[id].addv = 0;
    }

    void _build(int id, int l, int r) {
        a[id].sumv = a[id].addv = 0;
        if (l == r) {
            a[id].sumv = arr[l];
        } else {
            int m = l + (r - l) / 2;
            _build(id * 2, l, m);
            _build(id * 2 + 1, m + 1, r);
            maintain(id, l, r);
        }
    }
    void build(int l, int r, LL* _arr) {
        arr = _arr;
        L = l;
        R = r;
        _build(1, L, R);
    }

    void _add(int id, int l, int r, LL val) {
        if (QL <= l && r <= QR) {
            a[id].addv += val;
        } else {
            pushdown(id);
            int m = l + (r - l) / 2;
            if (QL <= m)
                _add(id * 2, l, m, val);
            else
                maintain(id * 2, l, m);

            if (m + 1 <= QR)
                _add(id * 2 + 1, m + 1, r, val);
            else
                maintain(id * 2 + 1, m + 1, r);
        }
        maintain(id, l, r);
    }
    void add(int l, int r, LL val) {
        QL = l, QR = r;
        _add(1, L, R, val);
    }

    void _query(int id, int l, int r) {
        maintain(id, l, r);
        if (QL <= l && r <= QR) {
            sumtr += a[id].sumv;
        } else {
            int m = l + (r - l) / 2;
            pushdown(id);
            if (QL <= m)
                _query(id * 2, l, m);
            else
                maintain(id * 2, l, m);

            if (m + 1 <= QR)
                _query(id * 2 + 1, m + 1, r);
            else
                maintain(id * 2 + 1, m + 1, r);
        }
    }
    LL query(int l, int r) {
        sumtr = 0;
        QL = l, QR = r;
        _query(1, L, R);
        return sumtr;
    }
};

SegTree tree;

int main() {
#ifdef D
    freopen("3372.in", "r", stdin);
#endif
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", arr + i);
    }
    tree.build(1, n, arr);
    for (int i = 0; i < m; i++) {
        int type, l, r, val;
        scanf("%d%d%d", &type, &l, &r);
        if (type == 1) {
            scanf("%d", &val);
            tree.add(l, r, val);
        } else {
            LL ans = tree.query(l, r);
            printf("%lld\n", ans);
        }
    }

    return 0;
}
