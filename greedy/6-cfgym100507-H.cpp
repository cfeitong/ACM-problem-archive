#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stack>

using namespace std;

const int N = 10010;
char s[N];
stack<int> st;
int p[N], ans[N];
int n;

int main() {
#ifdef D
    freopen("h.in", "r", stdin);
#endif
    while (~scanf("%d%s", &n, s + 1)) {
        while (!st.empty()) st.pop();
        for (int i = 1; i <= n * 2; ++i) {
            if (st.empty() || abs((int)s[st.top()] - s[i]) != 32)
                st.push(i);
            else {
                p[i] = st.top();
                p[st.top()] = i;
                st.pop();
            }
        }
        if (!st.empty()) {
            puts("Impossible");
            continue;
        }
        for (int i = 1; i <= 2 * n; i++) {
            if (s[i] < 'a')
                ans[i] = ans[i - 1];
            else
                ans[i] = ans[i - 1] + 1;
        }
        for (int i = 1; i <= 2 * n; i++) {
            if (s[i] < 'a') printf("%d ", ans[p[i]]);
        }
        puts("");
    }
    return 0;
}
