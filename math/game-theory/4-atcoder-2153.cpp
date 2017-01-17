#include <cstdio>
#include <cstring>
char s[100004];
int main() {
    scanf("%s", s);
    int l = strlen(s);
    bool all = (s[0] == s[l - 1]);
    puts((l + all) & 1 ? "First" : "Second");
    return 0;
}
