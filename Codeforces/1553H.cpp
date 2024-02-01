#include <bits/stdc++.h>

using namespace std;

// Problema: XOR and distance

#define MAXN 1<<19
#define lim 1<<k
#define inf MAXN<<4

int n, k;
int v[MAXN], treeL[MAXN], treeR[MAXN], px[MAXN<<1], py[MAXN<<1], save[MAXN<<1];

int g(int k) {
    return k^(k>>1);
}

void case1(int l, int r, int x) {
    if(r-l == 1) return;
    
    int mid=(l+r)/2;
        
    treeL[x]=x<<1|0;
    treeR[x]=x<<1|1;
    case1(l, mid, treeL[x]);
    case1(mid, r, treeR[x]);
        
    px[x]=max(px[treeL[x]]+l, px[treeR[x]]+mid)-l;
    py[x]=min(py[treeL[x]]+l, py[treeR[x]]+mid)-l;
    save[x]=min({save[treeL[x]], py[treeR[x]]+mid-px[treeL[x]]-l, save[treeR[x]]});
}

void case2(int l, int r, int v, int x, int tt) {
    if(r-l == 1) {
        assert(0);
        return;
    }
    int mid=(l+r)/2;
    
    if(tt > x) {
        case2(l, mid, treeL[v], x, tt-1);
        case2(mid, r, treeR[v], x, tt-1);
    } else {
        swap(treeL[v], treeR[v]);
    }
    
    px[v]=max(px[treeL[v]]+l, px[treeR[v]]+mid)-l;
    py[v]=min(py[treeL[v]]+l, py[treeR[v]]+mid)-l;
    save[v]=min({save[treeL[v]], py[treeR[v]]+mid-px[treeL[v]]-l, save[treeR[v]]});
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>n>>k;
    
    fill_n(px, 2*(lim), -inf);
    fill_n(py, 2*(lim), inf);
    fill_n(save, 2*(lim), inf);
    
    for(int i=0; i<n; i++) {
        cin>>v[i];
        px[(1<<k)+v[i]] = py[(1<<k)+v[i]] = 0;
    }
    
    case1(0, lim, 1);
    
    vector<int> resp(lim);
    
    int atual=0;
    resp[atual]=save[1];

    // f(i-1)    
    for (int x=1; x<(1<<k); x++) {
        int j=k-32+__builtin_clz(g(x) ^ g(x-1));
        atual^=1<<j;
        case2(0, lim, 1, j, k-1);
        resp[atual]=save[1];
    }

    for (int x : resp) cout<<x<<' ';
    
    return 0;
}