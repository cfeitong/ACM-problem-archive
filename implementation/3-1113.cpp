#include <cstdio>
#include <cstring>

const int N = 105;
const int MOD = 1e9 + 7;
typedef long long LL;

struct Matrix {
    LL a[N][N], n;
    Matrix(LL _n, LL _v = 0) : n(_n) {
        memset(a, 0, sizeof(a));
        for (int i = 0; i < n; i++) {
            a[i][i] = _v % MOD;
        }
    }
    Matrix operator*(const Matrix& rhs) const {
        Matrix ret(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    ret.a[i][j] += a[i][k] * rhs.a[k][j] % MOD;
                    ret.a[i][j] %= MOD;
                }
            }
        }
        return ret;
    }

    Matrix operator^(int power) const {
        Matrix ret(n, 1), a(*this);
        while (power) {
            if (power & 1) ret = ret * a;
            a = a * a;
            power /= 2;
        }
        return ret;
    }

    void input() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%lld", &a[i][j]);
            }
        }
    }
    void output() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                printf("%lld%c", a[i][j], "\n "[j < n - 1]);
            }
        }
    }
};

int main() {
#ifdef D
    freopen("1113.in", "r", stdin);
#endif
    int n, m;
    scanf("%d%d", &n, &m);
    Matrix mat(n, 1);
    mat.input();
    Matrix ans = mat ^ m;
    ans.output();

    return 0;
}