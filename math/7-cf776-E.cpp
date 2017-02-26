#include <iostream>
#include <cmath>

using namespace std;

typedef long long LL;

const LL MOD = 1000000007;

LL phi(LL n) {
    LL ans = n;
    for(LL i=2; i*i<=n; i++) {
        if(n%i==0) {
            ans=ans/i*(i-1);
            while(n%i==0) n/=i;
        }
    }
    if(n>1) ans=ans/n*(n-1);
    return ans;
}


int main() {
    LL n, k;
    cin >> n >> k;
    k = (k+1)/2;
    LL tmp = n;
    while (k--) {
        tmp = phi(tmp);
        if (tmp == 1) break;
    }
    cout << tmp%MOD << endl;

    return 0;
}
