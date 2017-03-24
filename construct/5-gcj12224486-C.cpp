#include <cstdio>
#include <cassert>
#include <map>
#include <tuple>
#include <queue>
#include <string>
#include <vector>

using namespace std;

const char SYM[] = "I/O/";
const char TAR[] = "I/O";
const int dx[] = {1, 1,  1, 0};
const int dy[] = {1, -1, 0, 1};


string operator*(string s, int n) {
    string ret;
    for (int i = 0; i < n; i++) {
        ret += s;
    }
    return ret;
}

void print(const vector<vector<int>>& s) {
    for (auto& line : s) {
        for (auto& v : line) {
            printf("%d ", v);
        }
        puts("");
    }
                                    }

void print(const vector<string>& s) {
    for (auto& line : s) {
        for (auto& ch : line) {
            printf("%c", ch);
        }
        puts("");
    }
}

vector<string> gen(int n) {
    string line = string(" ") * n;
    vector<string> ret(n, line);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ret[i][j] = SYM[j%4];
        }
    }

    return ret;
}

int sum(const vector<vector<int>>& g) {
    int ret = 0;
    for (auto& line : g) for (auto& v : line) ret += v;
    return ret;
}

int count(const vector<string>& g, int i, int j, int d, int n) {
    if (g[i][j] != '/') return 0;
    int y1 = i + dy[d], y2 = i - dy[d];
    int x1 = j + dx[d], x2 = j - dx[d];
#define check(v) if (v < 0 || v >= n) return 0
    check(y1); check(x1);
    check(y2); check(x2);
    if (g[y1][x1] == 'I' && g[y2][x2] == 'O') return 1;
    if (g[y1][x1] == 'O' && g[y2][x2] == 'I') return 1;
    return 0;
}

vector<vector<int>> count(const vector<string>& g) {
    int n = g.size();
    vector<vector<int>> ret(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int d = 0; d < 4; d++) {
                ret[i][j] += count(g, i, j, d, n);
            }
        }
    }
    return ret;
}

map<int, vector<pair<int,int>>> get_map(const vector<vector<int>>& g) {
    int n = g.size();
    map<int, vector<pair<int,int>>> ret;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ret[g[i][j]].emplace_back(i, j);
        }
    }
    return ret;
}

int main() {
    auto g = gen(15);
    auto v = count(g);
    auto m = get_map(v);

    int T; scanf("%d", &T);
    for (int kase = 1; kase <= T; kase++) {
        auto gg = g;
        auto vv = v;
        auto mm = m;
        int s = sum(vv);
        int d, n; scanf("%d%d", &d, &n);
        while (s > n) {
            if (s-n >= 3 && !mm[3].empty()) {
                auto p = mm[3].back(); mm[3].pop_back();
                gg[p.first][p.second] = 'O';
                s -= 3;
            } else if (s - n >= 1 && !mm[1].empty()) {
                auto p = mm[1].back(); mm[1].pop_back();
                gg[p.first][p.second] = 'O';
                s -= 1;
            }
        }
        assert(n == sum(count(gg)));
        printf("Case #%d:\n", kase);
        print(gg);
    }

    return 0;
}
