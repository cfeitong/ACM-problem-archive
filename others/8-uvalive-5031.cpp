#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

const int INF = 0x3f3f3f3f;
typedef long long LL;

struct Node {
    Node* ch[2];
    int val, rank, size;
    Node(int _v = 0) : val(_v) {
        size = 1;
        rank = rand();
        ch[0] = ch[1] = NULL;
    }
    int cmp(int x) {
        if (val == x) return -1;
        return x < val ? 0 : 1;
    }
};

struct Treap {
    Node* root;

    Treap() { init(); }
    ~Treap() { init(); }

    void init() { _init(root); }
    void _init(Node*& o) {
        if (!o) return;
        if (o->ch[0]) _init(o->ch[0]);
        if (o->ch[1]) _init(o->ch[1]);
        delete o;
        o = NULL;
    }

    void maintain(Node* o) {
        int sz = 1;
        if (o) {
            if (o->ch[0]) sz += o->ch[0]->size;
            if (o->ch[1]) sz += o->ch[1]->size;
            o->size = sz;
        }
    }

    void rotate(Node*& o, int d) {
        Node* k = o->ch[!d];
        o->ch[!d] = k->ch[d];
        k->ch[d] = o;
        maintain(o);
        maintain(k);
        o = k;
    }

    void insert(int val) { _insert(root, val); }
    void _insert(Node*& o, int val) {
        if (!o)
            o = new Node(val);
        else {
            int d = val < o->val ? 0 : 1;
            _insert(o->ch[d], val);
            if (o->rank < o->ch[d]->rank) rotate(o, !d);
        }
        maintain(o);
    }

    void remove(int val) { _remove(root, val); }
    void _remove(Node*& o, int val) {
        int d = o->cmp(val);
        if (d == -1) {
            if (o->ch[0] && o->ch[1]) {
                int d2 = o->ch[0]->rank < o->ch[1]->rank ? 0 : 1;
                rotate(o, d2);
                _remove(o->ch[d2], val);
            } else {
                Node* u = o;
                if (o->ch[0]) {
                    o = o->ch[0];
                } else if (o->ch[1]) {
                    o = o->ch[1];
                } else {
                    o = NULL;
                }
                delete u;
            }
        } else {
            _remove(o->ch[d], val);
        }
        maintain(o);
    }

    int kth(int k) { return _kth(root, k); }
    int _kth(Node* o, int k) {
        if (!o || k <= 0 || k > o->size) return 0;
        int sz = o->ch[1] ? o->ch[1]->size : 0;
        if (k == sz + 1)
            return o->val;
        else if (k <= sz)
            return _kth(o->ch[1], k);
        else
            return _kth(o->ch[0], k - sz - 1);
    }

    int rankof(int val) { return _rankof(root, val); }
    int _rankof(Node* o, int val) {
        if (!o) return 1;
        if (o->val >= val)
            return _rankof(o->ch[0], val);
        else
            return _rankof(o->ch[1], val) + 1 + (o->ch[0] ? o->ch[0]->size : 0);
    }

    void merge(Treap& o) { _merge(o.root); }
    void _merge(Node*& o) {
        if (o->ch[0]) _merge(o->ch[0]);
        if (o->ch[1]) _merge(o->ch[1]);
        insert(o->val);
        delete o;
        o = NULL;
    }
};

const int N = 1e5;

struct UniFind {
    int pa[N];
    // vector<int> set[N];
    UniFind() { init(); }
    void init() {
        for (int i = 0; i < N; i++) {
            pa[i] = i;
            // set[i].clear();
        }
    }
    int find(int k) { return pa[k] == k ? k : pa[k] = find(pa[k]); }
    void unite(int a, int b) {
        // if (set[a].size() < set[b].size()) {
        //     unit(b, a);
        //     return;
        // }
        pa[find(b)] = find(a);
        // while (!set[b].empty()) {
        //     set[a].push_back(set[b].back());
        //     set[b].pop_back();
        // }
    }
};

struct Op {
    char type;
    int x, v;
};

struct Edg {
    int a, b, use;
};

int n, m;
int w[N];

vector<Op> ops;
UniFind uf;
Treap tr[N];
vector<Edg> es;

void clean() {
    ops.clear();
    uf.init();
    es.clear();
    for (int i = 0; i < N; i++) {
        tr[i].init();
        w[i] = 0;
    }
}

void add_edg(int a, int b) {
    int pa = uf.find(a), pb = uf.find(b);
    if (pa == pb) return;
    if (tr[pa].root->size >= tr[pb].root->size) {
        uf.unite(a, b);
        uf.pa[pb] = pa;
        tr[pa].merge(tr[pb]);
    } else {
        uf.unite(b, a);
        tr[pb].merge(tr[pa]);
    }
}

int query(int x, int k) {
    int p = uf.find(x);
    int cur = tr[p].kth(k);
    // #ifdef D
    //     printf("tree %d(%d) is %d\n", x, k, cur);
    // #endif
    return cur;
}
void change_weight(int x, int v) {
    int p = uf.find(x);
    tr[p].remove(w[x]);
    tr[p].insert(v);
    w[x] = v;
}

int main() {
#ifdef D
    freopen("5031.in", "r", stdin);
#endif
    int kase = 0;
    while (1) {
        clean();
        scanf("%d%d ", &n, &m);
        if (!n && !m) break;
        for (int i = 1; i <= n; i++) {
            scanf("%d ", w + i);
        }
        for (int i = 0; i < m; i++) {
            int a, b;
            scanf(" %d%d ", &a, &b);
            es.push_back({a, b, 1});
        }
        char t;
        int x, v;
        for (scanf(" %c ", &t); t != 'E'; scanf(" %c ", &t)) {
            v = -INF;
            if (t == 'D') scanf(" %d ", &x), es[x - 1].use = 0;
            if (t == 'Q') scanf(" %d%d ", &x, &v);

            if (t == 'C') {

                scanf(" %d%d ", &x, &v);
                ops.push_back({t, x, w[x]});
                w[x] = v;
            } else {

                ops.push_back({t, x, v});
            }
        }

        for (int i = 1; i <= n; i++) {
            tr[i].insert(w[i]);
        }

        for (auto it : es) {
            if (!it.use) continue;
            add_edg(it.a, it.b);
        }

        reverse(begin(ops), end(ops));

        LL tot = 0, cnt = 0;
        for (auto it : ops) {
            if (it.type == 'D') add_edg(es[it.x - 1].a, es[it.x - 1].b);
            if (it.type == 'C') change_weight(it.x, it.v);
            if (it.type == 'Q') tot += query(it.x, it.v), cnt++;
        }
        printf("Case %d: %.6f\n", ++kase, cnt ? (double)tot / cnt : 0);
    }

    return 0;
}
