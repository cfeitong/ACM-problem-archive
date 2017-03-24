#include <cstdio>
#include <cstring>

using namespace std;

const int N = 105;

struct Matrix {
    int a[N][N], n;
    Matrix(int _n) : n(_n) { memset(a, 0, sizeof(a)); }
    Matrix operator*(const Matrix& rhs) const {
        Matrix ret(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    ret.a[i][j] += a[i][k] * rhs.a[k][j];
                }
            }
        }
        return ret;
    }

    void input() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &a[i][j]);
            }
        }
    }
    void output() {
        for (int i = 0; i < n; i++) {
            for (int j =0; j < n; j++) {
                printf("%d%c", a[i][j], "\n "[j<n-1]);
            }
        }
    }
};

int main() {
#ifdef D
    freopen("1137.in", "r", stdin);
#endif
    int n; scanf("%d", &n);
    Matrix m1(n), m2(n);
    m1.input(), m2.input();
    Matrix ans = m1 * m2;
    ans.output();

    return 0;
}