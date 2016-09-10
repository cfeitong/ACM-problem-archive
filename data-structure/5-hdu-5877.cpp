#include<cstdio>
#include<iostream>
#include<sstream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<climits>
#include<cmath>
#include<algorithm>
#include<queue>
#include<vector>
#include<stack>
#include<set>
#include<map>
#define INF 0x3f3f3f3f
#define eps 1e-8
using namespace std;
#define N 110000LL

typedef long long LL;

LL tr[N<<2];
LL sorted[N],toleft[20][N],val[20][N];
LL pa[N];
LL st[N], ed[N];
vector<LL> son[N];
LL a[N];
LL n, k;

void dfs(LL cur, LL &clock) {
    sorted[clock] = a[cur];
    st[cur] = clock++;
    for (LL i = 0; i < son[cur].size(); i++) {
        dfs(son[cur][i], clock);
    }
    ed[cur] = clock-1;
}

void init() {
    memset(val, 0, sizeof(val));
    memset(sorted, 0, sizeof(sorted));
    memset(pa, 0, sizeof(pa));
    memset(st, 0, sizeof(st));
    memset(ed, 0, sizeof(ed));
    memset(a, 0, sizeof(a));
    for (LL i = 0; i < N; i++) son[i].clear();
    for (LL i = 1; i <= n; i++) scanf("%lld", &a[i]);
    for (LL i = 1; i < n; i++) {
        int u, v; scanf("%d%d", &u, &v);
        pa[v] = u;
        son[u].push_back(v);
    }
    LL root = 1;
    while (pa[root]) root = pa[root];
    LL c = 0;
    dfs(root, c);
    for (LL i = 0; i < n; i++) {
        val[0][i] = sorted[i];
    }
}

void build(LL l, LL r, LL dep, LL rt) {
    if(l==r) {
        return;
    }
    LL mid=(l+r)>>1;
    LL lnum=mid-l+1;
    for(LL i=l; i<=r; i++) {
        if(val[dep][i]<sorted[mid]) {
            lnum--;
        }
    }
    LL lp=l,rp=mid+1;
    LL cur_lnum=0;
    for(LL i=l; i<=r; i++) {
        if(i==l) {
            toleft[dep][i]=0;
        } else {
            toleft[dep][i]=toleft[dep][i-1];
        }
        if(val[dep][i]<sorted[mid]) {
            toleft[dep][i]++;
            val[dep+1][lp++]=val[dep][i];
        } else if(val[dep][i]>sorted[mid]) {
            val[dep+1][rp++]=val[dep][i];
        } else {
            if(cur_lnum<lnum) {
                cur_lnum++;
                toleft[dep][i]++;
                val[dep+1][lp++]=val[dep][i];
            } else {
                val[dep+1][rp++]=val[dep][i];
            }
        }
    }
    build(l,mid,dep+1,rt<<1);
    build(mid+1,r,dep+1,rt<<1|1);
}

LL query(LL l, LL r, LL L, LL R, LL x, LL dep, LL rt) {
    if(l==r) {
        return val[dep][l]<=x;
    }
    LL lnum,cur_lnum,rnum,cur_rnum;
    LL mid=(l+r)>>1;
    if(l==L) {
        lnum=toleft[dep][R];
        cur_lnum=0;
    } else {
        lnum=toleft[dep][R]-toleft[dep][L-1];
        cur_lnum=toleft[dep][L-1];
    }
    if(sorted[mid]>x) {
        if(!lnum) {
            return 0;
        }
        LL newL=l+cur_lnum;
        LL newR=l+lnum+cur_lnum-1;
        return query(l,mid,newL,newR,x,dep+1,rt<<1);
    } else {
        LL rnum=R-L+1-lnum;
        LL cur_rnum=L-l-cur_lnum;
        if(!rnum) {
            return lnum;
        }
        LL newL=mid+cur_rnum+1;
        LL newR=mid+cur_rnum+rnum;
        return lnum+query(mid+1,r,newL,newR,x,dep+1,rt<<1|1);
    }
}

int main() {
    freopen("1010.in", "r", stdin);
    int cas;
    scanf("%d",&cas);
    for(int T=1; T<=cas; T++) {
        scanf("%lld%lld",&n,&k);
        init();
        // for(LL i=0; i<n; i++) {
        //     scanf("%d",&val[0][i]);
        //     sorted[i]=val[0][i];
        // }
        sort(sorted,sorted+n);
        build(0,n-1,0,1);

        LL ans = 0;
        for (LL i = 1; i <= n; i++) {
            ans += query(0, n-1, st[i]+1, ed[i], k/a[i], 0, 1);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
