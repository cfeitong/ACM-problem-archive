#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

int cnt[13];
char s[1234567];
char ns[1234566];
int tp;
char modi[10] = "1986";

int main() {
    scanf("%s", s);
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        cnt[s[i]-'0']++;
    }
    cnt[1]--; cnt[6]--; cnt[8]--; cnt[9]--;
    for (int i = 1; i <= 9; i++) {
        while (cnt[i]) {
            ns[tp++] = i+'0';
            cnt[i]--;
        }
    }
    ns[tp++] = '0'; ns[tp++] = '0'; ns[tp++] = '0'; ns[tp++] = '0';

    int mod = 0;
    for (int i = 0; i < tp; i++) {
        mod *= 10; mod += ns[i]-'0';
        mod %= 7;
    }

    int ok = 0;
    do {
        int tmod = 0;
        for (int i = 0; i < 4; i++) {
            tmod *= 10;
            tmod += modi[i]-'0';
            tmod %= 7;
        }
        if ((tmod + mod) % 7 == 0) {
            ok  = 1;
            break;
        }
    } while (next_permutation(modi, (char *)modi+4));

    if (!ok) {
        puts("0");
        return 0;
    }

    ns[tp-4] = 0;
    printf("%s%s", ns, modi);
    for (int i = 0; i < cnt[0]; i++) putchar('0');
    puts("");

    return 0;
}
