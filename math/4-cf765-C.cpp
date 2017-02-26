#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

typedef long long LL;
LL k, a, b;

int main() {
#ifdef D
    freopen("c.in", "r", stdin);
#endif
    while (cin >> k >> a >> b) {
        if (b > a) swap(a, b);
        if (k > a || (b < k && (a % k))) {
            cout << -1 << endl;
            continue;
        }

        cout << a / k + b / k << endl;
    }
    return 0;
}
