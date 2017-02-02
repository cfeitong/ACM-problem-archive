#include <iostream>
using namespace std;

int n, k;

int main() {
#ifdef D
    freopen("d.in", "r", stdin);
#endif
    while (cin >> n >> k) {
        if (k & 1) {
            for (int i = 1; i < (k + 1) / 2; i++) cout << i << ' ' << -i << ' ';
            for (int i = 1; i <= n - k; i++) cout << 0 << ' ';
        } else {
            for (int i = 1; i < k / 2; i++) cout << i << ' ' << -i << ' ';
            cout << k / 2 << ' ';
            for (int i = 1; i <= n - k; i++) cout << 0 << ' ';
        }
        cout << 0 << endl;
    }

    return 0;
}
