#include <iostream>

using namespace std;

int main() {
#ifdef D
    freopen("a.in", "r", stdin);
#endif
    int f;
    cin >> f;
    puts(f >= 7 ? "YES" : "NO");

    return 0;
}
