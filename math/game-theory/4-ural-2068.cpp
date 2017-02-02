#include <algorithm>
#include <iostream>
using namespace std;

int main() {
#ifdef D
    freopen("g.in", "r", stdin);
#endif
    int n;
    while (cin >> n) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            int t;
            cin >> t;
            sum += t - 1;
        }

        cout << (sum / 2 & 1 ? "Daenerys" : "Stannis") << endl;
    }

    return 0;
}
