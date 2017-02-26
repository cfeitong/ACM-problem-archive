#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <functional>
#include <map>
#include <numeric>
#include <set>
#include <vector>

using namespace std;

typedef long long LL;
int n;

#if 1
int sgf[] = {
    0, 1, 2, 1, 4, 3, 2, 1, 5,  6, 2, 1, 8,  7,  5,  9,
    8, 7, 3, 4, 7, 4, 2, 1, 10, 9, 3, 6, 11, 12, 14,
};

bool ans() {
    vector<int> sg;
    const int N = 1e5;
    static bool use[N];
    memset(use, 0, sizeof(use));
    int acc = 0;
    for (LL i = 2; i * i <= n; i++) {
        if (use[i]) continue;
        int cur = 0;
        for (LL k = i; k <= n; k *= i) {
            if (k < N) use[k] = 1;
            acc++;
            cur++;
        }
        if (cur) sg.push_back(sgf[cur]);
    }
    sg.push_back((n - acc) & 1);
    return accumulate(begin(sg), end(sg), 0, bit_xor<int>());
}

#else
map<int, int> sg;
const int N = 31;
int calc(int s) {
    if (sg.find(s) != end(sg)) return sg[s];
    set<int> st;
    for (int i = 1; i <= N; i++) {
        if (s & (1 << (i - 1))) {
            int t = s;
            for (int j = i; j <= N; j += i) {
                if (t & (1 << (j - 1))) t ^= 1 << (j - 1);
            }
            st.insert(calc(t));
        }
    }

    for (int i = 0; i <= N; i++) {
        if (st.find(i) == end(st)) return sg[s] = i;
    }
    assert(0);
    return -1;
}
void pre() {
    printf("{");
    sg.clear();
    sg[0] = 0;
    for (int i = 0; i < N; i++) {
        printf("%d, ", calc((1 << i) - 1));
    }
    printf("}\n");
}

#endif

int main() {
#ifdef D
    freopen("a.in", "r", stdin);
#endif
#if 1
    while (~scanf("%d", &n)) puts(ans() ? "Vasya" : "Petya");
#else
    pre();
#endif
    return 0;
}
