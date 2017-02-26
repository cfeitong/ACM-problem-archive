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
    freopen("a.in", "r", stdin);
#endif

    int n;
    scanf("%d", &n);
    char tmp[10];
    scanf("%s", tmp);
    for (int i = 0; i < n; i++) scanf("%s", tmp);
    puts(n & 1 ? "contest" : "home");

    return 0;
}
