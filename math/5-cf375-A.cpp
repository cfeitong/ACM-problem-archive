
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn=5111;

char mat[maxn][maxn];
int n, m;
int ones[maxn][maxn];
int tmp[maxn];

int precalc(int i, int j) {
    if (mat[i][j] == '0') ones[i][j] = 0;
    if (ones[i][j] >= 0) return ones[i][j];
    if (j == m) return ones[i][j] = 1;
    return ones[i][j] = 1 + precalc(i, j+1);
}

int main() {
    freopen("tmp.in", "r", stdin);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%s", (char*)mat[i]+1);
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            ones[i][j] = -1;

    int ans = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            tmp[j] = precalc(j, i);
        }
        sort(tmp+1, tmp+n+1);
        for (int j = 1; j <= n; j++) {
            ans = max(ans, tmp[j]*(n-j+1));
        }
    }
    printf("%d\n", ans);

}
