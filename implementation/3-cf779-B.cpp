#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    string s;
    int n;
    bool ok = 0;
    while (cin >> s >> n) {
        ok = 0;
        reverse(begin(s), end(s));
        int z=0, o=0;
        for (auto ch : s) {
            if (ch == '0') z++;
            else o++;
            if (z == n) {
                ok = 1;
                break;
            }
        }

        if (ok) cout << o << endl;
        else cout << s.size()-(z ? 1 : 0) << endl;

    }

    return 0;
}
