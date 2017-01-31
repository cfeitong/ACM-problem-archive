#include <cstdio>

using namespace std;

const int N = 1e5 + 5;

typedef long long LL;

LL a[N];
LL MOD;

struct Node {
    LL addv, sumv, mulv;
};

struct SegTree {
    Node a[N * 4];
    LL* arr;
    int L, R, QL, QR;
    LL sumtr;

    void pushdown(int id) {
        int lc = id * 2, rc = id * 2 + 1;
        a[lc].mulv = a[lc].mulv * a[id].mulv % MOD;
        a[rc].mulv = a[rc].mulv * a[id].mulv % MOD;
        a[lc].addv = a[lc].addv * a[id].mulv % MOD;
        a[rc].addv = a[rc].addv * a[id].mulv % MOD;
        a[lc].addv = (a[lc].addv + a[id].addv) % MOD;
        a[rc].addv = (a[rc].addv + a[id].addv) % MOD;
        a[id].addv = 0;
        a[id].mulv = 1;
    }

    void maintain(int id, int l, int r) {
        int lc = id * 2, rc = id * 2 + 1;
        if (l != r) {
            a[id].sumv = (a[lc].sumv + a[rc].sumv) % MOD;
        }
        a[id].sumv = a[id].sumv * a[id].mulv % MOD;
        a[id].sumv = (a[id].sumv + a[id].addv * (r - l + 1) % MOD) % MOD;
        if (l == r) a[id].addv = 0, a[id].mulv = 1;
    }

    void _build(int id, int l, int r) {
        a[id].sumv = a[id].addv = 0;
        a[id].mulv = 1;
        if (l == r) {
            a[id].sumv = arr[l];
        } else {
            int m = (l + r) / 2;
            _build(id * 2, l, m);
            _build(id * 2 + 1, m + 1, r);
            maintain(id, l, r);
        }
    }

    void build(int l, int r, LL* _arr) {
        arr = _arr;
        L = l;
        R = r;
        _build(1, l, r);
    }

    void _add(int id, int l, int r, LL val) {
        if (QL <= l && r <= QR) {
            a[id].addv = (a[id].addv + val) % MOD;
        } else {
            pushdown(id);
            int m = (l + r) / 2;

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
            sumtr = (sumtr + a[id].sumv) % MOD;
        } else {
            pushdown(id);
            int m = (l + r) / 2;
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
        QL = l, QR = r;
        sumtr = 0;
        _query(1, L, R);
        return sumtr;
    }

    void _mul(int id, int l, int r, LL val) {
        if (QL <= l && r <= QR) {
            a[id].mulv = (a[id].mulv * val) % MOD;
            a[id].addv = (a[id].addv * val) % MOD;
        } else {
            pushdown(id);
            int m = (l + r) / 2;

            if (QL <= m)
                _mul(id * 2, l, m, val);
            else
                maintain(id * 2, l, m);

            if (m + 1 <= QR)
                _mul(id * 2 + 1, m + 1, r, val);
            else
                maintain(id * 2 + 1, m + 1, r);
        }
        maintain(id, l, r);
    }
    void mul(int l, int r, LL val) {
        QL = l, QR = r;
        _mul(1, L, R, val);
    }
};

SegTree tree;
int n, m;

int main() {
#ifdef D
    freopen("3373.in", "r", stdin);
#endif
    scanf("%d%d%lld", &n, &m, &MOD);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", a + i);
    }
    tree.build(1, n, a);
    for (int i = 0; i < m; i++) {
        int type, l, r;
        scanf("%d%d%d", &type, &l, &r);
        if (type == 1) {
            LL k;
            scanf("%lld", &k);
            tree.mul(l, r, k);
        } else if (type == 2) {
            LL k;
            scanf("%lld", &k);
            tree.add(l, r, k);
        } else { // type == 3
            LL ans = tree.query(l, r);
            printf("%lld\n", ans);
        }
    }
    return 0;
}
