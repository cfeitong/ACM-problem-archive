#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <random>

using namespace std;

// const int N = 2e5;

// value type
typedef int VT;
const VT INF = 0x3f3f3f3f;

struct Node {
    Node* ch[2];
    int rank, size;
    VT val;
    int cmp(VT x) {
        if (x == val) return -1;
        return x < val ? 0 : 1;
    }
    Node(VT x = 0) : val(x) {
        ch[0] = ch[1] = NULL;
        rank = rand();
        size = 1;
    }
};

struct Treap {

    Node* root;

    void init() { root = NULL; }

    void maintain(Node* o) {
        if (!o) return;
        int cur = 1;
        if (o->ch[0]) cur += o->ch[0]->size;
        if (o->ch[1]) cur += o->ch[1]->size;
        o->size = cur;
    }

    // d=0: left rotate d=1: right rotate
    void rotate(Node*& o, int d) {
        Node* k = o->ch[d ^ 1];
        o->ch[d ^ 1] = k->ch[d];
        k->ch[d] = o;
        maintain(o);
        maintain(k);
        o = k;
    }

    // insert x in the subtree rooted at o
    void insert(VT x) { _insert(root, x); }
    void _insert(Node*& o, VT x) {
        if (!o) {
            o = new Node(x);
        } else {
            int d = x < o->val ? 0 : 1;
            _insert(o->ch[d], x);
            if (o->ch[d]->rank > o->rank) {
                rotate(o, d ^ 1);
            }
        }
        maintain(o);
    }

    // make sure x is in the subtree rooted at o
    void remove(VT x) { _remove(root, x); }
    void _remove(Node*& o, VT x) {
        int d = o->cmp(x);
        if (d == -1) {
            Node* u = 0;
            if (o->ch[0] && o->ch[1]) {
                int d2 = o->ch[0]->rank > o->ch[1]->rank ? 1 : 0;
                rotate(o, d2);
                _remove(o->ch[d2], x);
            } else {
                if (!o->ch[0])
                    o = o->ch[1];
                else
                    o = o->ch[0];
                delete u;
            }

        } else {
            _remove(o->ch[d], x);
        }
        maintain(o);
    }

    // return NULL if not exits
    Node* find(VT x) { return _find(root, x); }
    Node* _find(Node* o, VT x) {
        if (!o) return NULL;
        if (x == o->val) return o;
        return x < o->val ? _find(o->ch[0], x) : _find(o->ch[1], x);
    }

    Node* kth(int k) { return _kth(root, k); }
    Node* _kth(Node* o, int k) {
        if (!o || k <= 0 || k > o->size) return NULL;
        int sz = o->ch[0] ? o->ch[0]->size : 0;
        if (k == sz + 1)
            return o;
        else if (k <= sz)
            return _kth(o->ch[0], k);
        else
            return _kth(o->ch[1], k - sz - 1);
    }

    // return count(val in tree < x)+1;
    int rankof(VT x) { return _rankof(root, x); }
    int _rankof(Node* o, VT x) {
        if (!o) return 1;
        if (x <= o->val) return _rankof(o->ch[0], x);
        return _rankof(o->ch[1], x) + (o->ch[0] ? o->ch[0]->size : 0) + 1;
    }

    // max val that < x
    VT pred(VT x) { return _pred(root, x); }
    VT _pred(Node* o, VT x) {
        if (!o) return -INF;
        if (o->val >= x) return _pred(o->ch[0], x);
        return max(o->val, _pred(o->ch[1], x));
    }

    // min val that > x
    VT succ(VT x) { return _succ(root, x); }
    VT _succ(Node* o, VT x) {
        if (!o) return INF;
        if (o->val <= x) return _succ(o->ch[1], x);
        return min(o->val, _succ(o->ch[0], x));
    }
};

Treap tree;

int main() {
#ifdef D
    freopen("3369.in", "r", stdin);
#endif
    srand(0xdeadbeef);
    tree.init();
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int opt, x;
        scanf("%d%d", &opt, &x);
        switch (opt) {
        case 1: {
            tree.insert(x);
            break;
        }
        case 2: {
            tree.remove(x);
            break;
        }
        case 3: {
            int r = tree.rankof(x);
            printf("%d\n", r);
            break;
        }
        case 4: {
            Node* v = tree.kth(x);
            printf("%d\n", v->val);
            break;
        }
        case 5: {
            int v = tree.pred(x);
            printf("%d\n", v);
            break;
        }
        case 6: {
            int v = tree.succ(x);
            printf("%d\n", v);
            break;
        }
        }
    }
    return 0;
}
