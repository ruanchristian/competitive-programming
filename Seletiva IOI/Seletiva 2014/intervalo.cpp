#include <bits/stdc++.h>

using namespace std;

const int mxN = 2*(1e5+1);
typedef long long ll;

ll bit[mxN];

int n, q, ax1[mxN], ax2[mxN], freq[mxN];
bool mark[mxN];

void update_bit(int x, int v) {
    for (; x <= n+q; x+=(x&-x)) {
        bit[x]+=v*1ll;
    }
}

void f_upd(int x, int v) {
    for(; x <= n+q; x+=(x&-x)) {
        freq[x]+=v;
    }
}

ll query(int x) {
    ll ans=0;
    for(; x>0; x-=(x&-x)) {
        ans+=bit[x];
    }
    return ans;
}

int freq_chk(int x) {
    int ans=0;
    for (; x>0; x-=(x&-x)) {
        ans+=freq[x];
    }
    return ans;
}

int proc(int v) {
    int l=1, r=n+q, ans=-1;
    
    while(l<=r) {
        int mid=(l+r)/2;
        int tmp=freq_chk(mid);
        
        if(tmp>=v) {
            ans=mid;
            r=mid-1;
        } else l=mid+1;
    }
    
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>n;
    
    for (int i=1; i<=n; i++) {
        cin>>ax2[i];
        ax1[i]=i;
    }
    cin>>q;
    
    for (int i=1; i<=n+q; i++) f_upd(i, 1);
    for (int i=n+1; i<=n+q; i++) {
        char op; 
        cin>>op>>ax1[i]>>ax2[i];
        if(op=='I') {
            ax1[i]++;
        } else {
            mark[i]=1;
        }
    }
    
    for (int i=n+q; i>0; i--) {
        if(mark[i]) {
            ax1[i]=proc(ax1[i]);
            ax2[i]=proc(ax2[i]);
        } else {
            ax1[i]=proc(ax1[i]);
            f_upd(ax1[i], -1);
        }
    }
    
    for (int i=1; i<=n+q; i++) {
        if(mark[i]) {
            cout<<query(ax2[i])-query(ax1[i]-1)<<'\n';
        } else {
            update_bit(ax1[i], ax2[i]);
        }
    }
    
    return 0;
}