#include <cstdio>
#include <iostream>

using namespace std;

int main() {
#ifdef D
    freopen("e.in", "r", stdin);
#endif
    int a, b, c;
    cin >> a >> b >> c;
    int ans = 0x3f3f3f3f;
    ans = min(ans, a - b - c);
    ans = min(ans, a - b + c);
    ans = min(ans, a + b - c);
    ans = min(ans, a + b + c);
    ans = min(ans, a - b * c);
    ans = min(ans, a * b - c);
    ans = min(ans, a * b * c);
    ans = min(ans, a * b + c);
    ans = min(ans, a + b * c);
    cout << ans << endl;

    return 0;
}
