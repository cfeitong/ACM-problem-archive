#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int n, k;
vector<string> ans;
vector<string> names;

void gen() {
    for (int j = 0; j < 10; j++) {
        stringstream ss;
        ss << char('A' + j);
        ss << char('a' + j);
        names.push_back(ss.str());
        for (int i = 1; i < 8; i++) {
            ss << char('a' + j);
            names.push_back(ss.str());
        }
    }
}

int p = 0;

int main() {
    freopen("C.in", "r", stdin);
    gen();
    cin >> n >> k;
    for (int i = 0; i < k-1; i++) ans.push_back(names[p++]);
    for (int i = 0; i < n - k + 1; i++) {
        string cur;
        cin >> cur;
        if (cur == "YES") {
            ans.push_back(names[p++]);
        } else {
            ans.push_back(*(end(ans)-k+1));
        }
    }

    for (auto it : ans) {
        cout << it << ' ';
    }
    cout << endl;

    return 0;
}