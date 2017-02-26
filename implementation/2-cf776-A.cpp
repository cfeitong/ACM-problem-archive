#include <iostream>
#include <string>

using namespace std;

string a, b;

int main() {
    #ifdef D
    freopen("a.in", "r", stdin);
    #endif
    cin >> a >> b;
    int n; cin >> n;
    cout << a << ' ' << b << endl;
    for (int i = 0; i < n; i++) {
        string k, r;
        cin >> k >> r;
        if (a == k) a = r;
        else b = r;
        cout << a << ' ' << b << endl;
    }

    return 0;
}
