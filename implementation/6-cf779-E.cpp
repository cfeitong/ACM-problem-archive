#include <algorithm>
#include <cassert>
#include <cctype>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;
int n, m;

typedef map<string,string> Env;

string get_val(string id, Env& env) {
    if (env.count(id)) return env[id];
    return id;
}

struct Expr {
    string var;
    string op;
    string x1, x2;
    string eval(Env& env) {
        // cout << var << " = " << x1 << " " << op << " " << x2 << endl;
        string res(m, '0');
        string v1 = get_val(x1, env);
        string v2 = get_val(x2, env);
        for (int i = 0; i < m; i++) {
            if (op == "XOR") {
                res[i] = '0' + (v1[i] != v2[i]);
            } else if (op == "AND") {
                res[i] = '0' + (v1[i]=='1' && v2[i] == '1');
            } else if (op == "OR") {
                res[i] = '0' + (v1[i]=='1' || v2[i] == '1');
            } else { // instant number
                res = v1;
            }
        }
        return env[var] = res;
    }
};

vector<Expr> exprs;

Expr parse(string line) {
    string var, x1, x2, op;
    string::iterator iter = begin(line);
    while (*iter != ' ') {
        var += *iter;
        iter++;
    }
    while (*iter++ != '=') ;
    while (isspace(*iter)) iter++;
    while (!isspace(*iter)) {
        x1 += *iter;
        iter++;
    }
    if (*iter == '\n') return Expr{var, op, x1, x2};
    while (isspace(*iter)) iter++;
    while (!isspace(*iter)) {
        op += *iter;
        iter++;
    }
    while (isspace(*iter)) iter++;
    while (!isspace(*iter)) {
        x2 += *iter;
        iter++;
    }
    return Expr{var, op, x1, x2};
}

vector<int> execute(Env& env) {
    vector<int> ret(m, 0);
    for (auto& expr : exprs) {
        string res = expr.eval(env);
        for (int i = 0; i < m; i++) {
            if (res[i] == '1') ret[i]++;
        }
        env[expr.var] = res;
    }
    return ret;
}

int main() {
#ifdef D
    freopen("e.in", "r", stdin);
#else
    ios::sync_with_stdio(0);
    cin.tie(0);
#endif
    cin >> n >> m;
    string dummy; getline(cin, dummy); // discard previous end of line
    for (int i = 0; i < n; i++) {
        string line;
        getline(cin, line); line += "\n";
        exprs.push_back(parse(line));
    }

    string ones(m,'1'), zeros(m,'0');
    Env env1, env0;
    env1["?"] = ones;
    env0["?"] = zeros;
    auto res1 = execute(env1);
    // cout << "----------------" << endl;
    auto res0 = execute(env0);

    string min_ans(m, '0'), max_ans(m, '0');
    for (int i = 0; i < m; i++) {
        min_ans[i] += (res1[i] < res0[i]);
        max_ans[i] += (res1[i] > res0[i]);
    }

    cout << min_ans << endl;
    cout << max_ans << endl;

    return 0;
}
