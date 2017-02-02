#include <cstring>
#include <iostream>
#include <string>

using namespace std;

int n;

void read(string& s) {
    s = "";
    while (s.empty()) getline(cin, s);
}

int problem[20];

string align(string s, int len) {
    while ((int)s.size() < len) s += ' ';
    return s;
}

int main() {
#ifdef D
    freopen("l.in", "r", stdin);
#endif
    cin >> n;
    cout << "+------------------------------+--------+-------------+" << endl;
    cout << "|Contest name                  |Date    |ABCDEFGHIJKLM|" << endl;
    cout << "+------------------------------+--------+-------------+" << endl;
    while (n--) {
        memset(problem, -1, sizeof(problem));
        string name, date;
        read(name);
        read(date);

        int s, p;
        cin >> p >> s;
        for (int i = 0; i < s; i++) {
            string prob;
            read(prob);
            if (prob[2] == 'A')
                problem[prob[0] - 'A'] = 1;
            else if (problem[prob[0] - 'A'] != 1)
                problem[prob[0] - 'A'] = 2;
        }
        cout << "|" << align(name, 30) << "|" << align(date, 8);
        cout << "|";
        for (int i = 0; i < 13; i++) {
            if (i >= p) {
                cout << " ";
                continue;
            }
            if (problem[i] == -1) cout << ".";
            if (problem[i] == 1) cout << "o";
            if (problem[i] == 2) cout << "x";
        }
        cout << "|" << endl;
        cout << "+------------------------------+--------+-------------+"
             << endl;
    }

    return 0;
}
