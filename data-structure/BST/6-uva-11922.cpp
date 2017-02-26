#include <algorithm>
#include <cstdio>
using namespace std;

typedef int VT;
const int N = 2e5;

struct Node {
    Node* c[2];
    Node* p;
    int sz, flip;
    VT v;
} mem[N], *cur, *nil;

Node* new_node(VT x, Node* p) {
    cur->c[0] = cur->c[1] = nil, cur->p = p;
    cur->sz = 1;
    cur->v = x;
    cur->flip = 0;
    return cur++;
}

void init() {
    cur = mem;
    nil = new_node(0, cur);
    nil->c[0] = nil->c[1] = nil;
    nil->sz = 0;
}

struct Splay {
    Node* root;
    void init() { root = nil; }

    void pull(Node* o) {
        if (o == nil) return;
        push(o);
        push(o->c[0]);
        push(o->c[1]);
        o->sz = o->c[0]->sz + o->c[1]->sz + 1;
    }

    void push(Node* o) {
        if (o == nil) return;
        if (o->flip) {
            o->flip = 0;
            swap(o->c[0], o->c[1]);
            o->c[0]->flip ^= 1;
            o->c[1]->flip ^= 1;
        }
    }

    // zig(d=0), zag(d=1)
    // o is rotated up
    void rotate(Node* o, int d) {
        if (o == nil) return;
        Node* k = o->p;
        k->c[!d] = o->c[d], o->p = k->p;
        if (o->c[d] != nil) o->c[d]->p = k;
        if (k->p != nil) k->p->c[k->p->c[1] == k] = o;
        o->c[d] = k, k->p = o;
        pull(k), pull(o);
    }

    // splay o to the child of f
    void splay(Node* o, Node* f) {
        static Node* stack[N];
        int top = 0;
        stack[top++] = o;
        for (Node* k = o; k != f; k = k->p) stack[top++] = k->p;
        while (top) push(stack[--top]);
        while (o->p != f) {
            Node* k = o->p;
            if (k->p == f) {
                rotate(o, o == k->c[0]);
            } else {
                int d = k->p->c[0] == k;
                if (k->c[d] == o) {
                    rotate(o, !d), rotate(o, d);
                } else {
                    rotate(k, d), rotate(o, d);
                }
            }
        }
        pull(o);
        if (f == nil) root = o;
    }

    // splay kth(1~n) elementh to the child of f
    void select(int k, Node* f) {
        Node* o = root;
        push(o);
        int tmp;
        while ((tmp = o->c[0]->sz) != k) {
            k < tmp ? o = o->c[0] : (k -= tmp + 1, o = o->c[1]);
            push(o);
        }
        splay(o, f);
    }

    // splay range [l,r] to root->c[1]->c[0]
    void select(int l, int r) { select(l - 1, nil), select(r + 1, root); }

    Node* make_tree(int* a, int l, int r, Node* p) {
        if (l > r) return nil;
        int m = (l + r) / 2;
        Node* o = new_node(a[m], p);
        o->c[0] = make_tree(a, l, m - 1, o);
        o->c[1] = make_tree(a, m + 1, r, o);
        pull(o);
        if (o->p == nil) root = o;
        return o;
    }

    // remove from l-th to r-th [l,r]
    Node* remove(int l, int r) {
        select(l, r);
        Node* ret = root->c[1]->c[0];
        root->c[1]->c[0] = nil;
        pull(root->c[1]), pull(root);
        splay(root->c[1], nil);
        return ret;
    }

    void print(Node* o) {
        if (o == nil) return;
        push(o);
        print(o->c[0]);
        if (o->v > 0) printf("%d\n", o->v);
        print(o->c[1]);
    }

    Node* rmost() {
        Node* e = root;
        push(e);
        while (e->c[1] != nil) e = e->c[1], push(e);
        return e;
    }
};

int a[N];
int n;

Splay tr;

void op(int l, int r) {
    if (r == n) {
        if (l == 1)
            tr.root->flip ^= 1;
        else {
            tr.select(l - 1, nil);
            tr.root->c[1]->flip ^= 1;
        }
    } else {
        Node* o = tr.remove(l, r);

        Node* e = tr.rmost();

        o->p = e;
        e->c[1] = o;
        o->flip ^= 1;
        tr.pull(e);
        tr.splay(e, nil);
    }
}

int main() {
#ifdef D
    freopen("11922.in", "r", stdin);
#endif
    init();
    tr.init();

    int m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) a[i] = i;
    a[0] = -1, a[n + 1] = -2;
    ;

    tr.make_tree(a, 0, n, nil);
    // tr.print(tr.root), puts("");

    while (m--) {
        int a, b;
        scanf("%d%d", &a, &b);
        op(a, b);
        // tr.print(tr.root), puts("");
    }

    tr.print(tr.root);

    return 0;
}
