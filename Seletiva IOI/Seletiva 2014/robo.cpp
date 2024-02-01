#include <bits/stdc++.h>

using namespace std;

const int mxN = 1e5+1;

int y, x, ans=1, seg[4*mxN], lz[4*mxN];

void sla(int node, int l, int r) {
    if(lz[node] != -1) {
        //segmento ok
        seg[node]=lz[node]*(r-l+1);
        
        if(l!=r) {
            lz[2*node]=lz[2*node+1]=lz[node];
        }
        lz[node]=-1;
    }
}

void update(int node, int l, int r, int i, int j, int v) {
    sla(node, l, r);
    
    if(l >= j || r < i) return;
    if(i<=l && j>=r) {
        seg[node]=(r-l+1)*v;
        
        if(l!=r) {
            lz[2*node]=lz[2*node+1]=v;
        }
        return;
    }
    int mid=(l+r)>>1;
    
    update(2*node, l, mid, i, j, v);
    update(2*node+1, mid+1, r, i, j, v);
    
    seg[node]=seg[2*node]+seg[2*node+1];
}

int qry(int node, int l, int r, int i, int j) {
    sla(node, l, r);
    if(l >= j || r < i) return 0;
    if(i<=l && j>=r) return seg[node];
    
    int mid=(l+r)>>1;
    
    return qry(2*node, l, mid, i, j)+qry(2*node+1, mid+1, r, i, j);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>y>>x;
    
    memset(lz, -1, sizeof lz);
    
    for (int k=0; k<x-1; k++) {
        int i, f; cin>>i>>f;
        
        update(1, 0, y, i, f, 1);
        int r=qry(1, 0, y, 0, y);
        
        if(r==y+1) {
            update(1, 0, y, 0, y, 0);
            update(1, 0, y, i, f, 1);
            ans+=2;
        }
    }
    
    cout<<ans<<endl;

    return 0;
}