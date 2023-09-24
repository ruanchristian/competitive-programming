#include <bits/stdc++.h>

using namespace std;

// Segment Tree

#define MAXN 100005

int n, q, tree[4*MAXN], vec[MAXN];

void build(int node, int l, int r) {
    if (l == r) {
        tree[node] = vec[r];
        return;
    }
    
    int mid = (l+r) >> 1;
    build(2*node+1, l, mid);
    build(2*node+2, mid+1, r);
    
    // 2*node+1 é o nó do filho da esquerda, 2*node+2 é o da direita
    
    tree[node] = tree[2*node+1] + tree[2*node+2];
}

void update(int node, int ll, int rr, int pos, int val) {
    if (ll == rr) {
        tree[node] = val;
        vec[ll] = val;
        return;
    }
    
    int mid = (ll+rr) >> 1;
    
    if (ll <= pos && pos <= mid) update(2*node+1, ll, mid, pos, val);
    else update(2*node+2, mid+1, rr, pos, val);
    
    tree[node] = tree[2*node+1] + tree[2*node+2];
}

int query(int node, int ll, int rr, int l, int r) {
    if (l > rr || r < ll) return 0;
    if (l <= ll && r >= rr) return tree[node];
    
    int mid = (ll+rr) >> 1;
    
    return query(2*node+1, ll, mid, l, r)+query(2*node+2, mid+1, rr, l, r);
}

int main() {
    // ...

    return 0;
}