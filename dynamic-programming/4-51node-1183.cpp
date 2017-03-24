#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 1e3 + 3;
int dp[N][N];
char s1[N], s2[N];

int main() {
#ifdef D
    freopen("1183.in", "r", stdin);
#endif
    scanf("%s %s", s1, s2);
    int l1 = strlen(s1), l2 = strlen(s2);
    for (int i = 0; i < l1; i++) dp[i][0] = i;
    for (int j = 0; j < l2; j++) dp[0][j] = j;
    for (int i = 1; i <= l1; i++)
        for (int j = 1; j <= l2; j++) {
            int cur = dp[i - 1][j - 1] + (s1[i - 1] != s2[j - 1]);
            cur = min(cur, dp[i - 1][j] + 1);
            cur = min(cur, dp[i][j - 1] + 1);
            dp[i][j] = cur;
        }

    printf("%d\n", dp[l1][l2]);

    return 0;
}