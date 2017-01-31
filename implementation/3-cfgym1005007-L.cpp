#include <cmath>
#include <iostream>
#include <string>

using namespace std;

int main() {
#ifdef D
    freopen("l.in", "r", stdin);
#endif
    int n;
    cin >> n;
    int ans = 0;
    int cur = 1;
    for (int i = 0; i < n; i++) {
        string t;
        cin >> t;
        int nxt;
        if (t[0] == 'A' || t[0] == 'P' || t[0] == 'O' || t[0] == 'R') {
            nxt = 1;
        } else if (t[0] == 'B' || t[0] == 'M' || t[0] == 'S') {
            nxt = 2;
        } else {
            nxt = 3;
        }
        ans += abs(cur - nxt);
        cur = nxt;
    }
    cout << ans << endl;

    return 0;
}
