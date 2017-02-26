#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

int main() {
#ifdef D
    freopen("b.in", "r", stdin);
#endif

    static char s[1000];
    static bool use[100];
    scanf("%s", s);
    int len = strlen(s);
    vector<int> vs;
    for (int i = 0; i < len; i++) {
        int v = s[i] - 'a';
        if (!use[v]) vs.push_back(v);
        use[v] = 1;
    }

    bool ok = 1;
    for (int i = 0; i < vs.size(); i++) {
        if (vs[i] != i) ok = 0;
    }

    puts(ok ? "YES" : "NO");

    return 0;
}
