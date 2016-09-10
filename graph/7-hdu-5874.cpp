#include <stdio.h>
#include <string.h>
#include <iostream>
#include <queue>
using namespace std;

int main() {
    long long n,m;
    while(cin >> n >> m) {
        long long tmp = n*n / 4;
        if (tmp > m) {
            cout << "F" << endl;
        }
        else {
            cout << "T" << endl;
        }
    }
    return 0;
}
