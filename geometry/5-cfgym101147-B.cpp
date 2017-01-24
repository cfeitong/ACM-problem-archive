#include <algorithm>
#include <cmath>
#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

typedef double LD;

struct Rect {
    int x1, y1, x2, y2;
};

const int N = 111;
Rect rs[N];

LD dist(int x1, int y1, int x2, int y2) {
    LD dx = x1 - x2, dy = y1 - y2;
    return sqrt(dx * dx + dy * dy);
}

LD dist(Rect a, Rect b) {
    if (a.x1 > b.x1) swap(a, b);
    if (b.x1 < a.x2) {
        if (b.y1 > a.y2) return b.y1 - a.y2;
        if (b.y2 < a.y1) return a.y1 - b.y2;
        return 0;
    } else {
        if (b.y1 > a.y2) return dist(a.x2, a.y2, b.x1, b.y1);
        if (b.y2 < a.y1) return dist(a.x2, a.y1, b.x1, b.y2);
        return b.x1 - a.x2;
    }
}

LD d[N][N];

int main() {
#ifdef D
    freopen("b.in", "r", stdin);
#else
    freopen("street.in", "r", stdin);
#endif
    int T;
    for (scanf("%d", &T); T--;) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                d[i][j] = 1e200;
            }
        }
        int n, l, r;
        scanf("%d%d%d", &n, &r, &l);
        rs[0] = Rect{0, 0, l, 0};
        for (int i = 1; i <= n; i++) {
            int h, w, d, k;
            scanf("%d%d%d%d", &h, &w, &d, &k);
            rs[i] = k ? Rect{l - w, d, l, (d + h) < r ? (d + h) : (r)}
                      : Rect{0, d, w, (d + h) < r ? (d + h) : (r)};
        }
        rs[++n] = Rect{0, r, l, r};

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                d[i][j] = d[j][i] = dist(rs[i], rs[j]);
            }
        }

        for (int k = 0; k <= n; k++) {
            for (int i = 0; i <= n; i++) {
                for (int j = 0; j <= n; j++) {
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                }
            }
        }

        printf("%.6f\n", d[0][n]);
    }
    return 0;
}
