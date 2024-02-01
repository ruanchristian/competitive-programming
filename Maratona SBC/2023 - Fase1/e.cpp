#include <bits/stdc++.h>
 
using namespace std;

// Extraindo polen - SBC
 
const int mxN = 1e6+2;
typedef long long ll;
 
int n, k, v[mxN], dp[mxN];
 
int sum(int x) {
    int sum=0;
    while(x) {
        sum+=x%10;
        x/=10;
    }
    return sum;
}
 
int calcula(int x, int& m) {
    if (x<=m) return 0;
    int &res=dp[x];
    if(~res) return res;
    res=1+calcula(x-sum(x), m);

    return res;
}
 
int ok(int m) {
    int s=0;
    for (int i=0; i<n; i++) {
        s+=calcula(v[i], m);
        if(s>=k) return -1;
    }
    return s;
}
 
int upd(int x, int& bst) {
    if (x<=bst) return x;
    int& res=dp[x];
    if(~res) return res;
    res=upd(x-sum(x), bst);
    
    return res;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>n>>k;
    
    for (int i=0; i<n; i++) cin>>v[i];
    sort(v, v+n);
    
    int l=0, r=v[n-1], ans=0, best=r;
    
    while(l<=r) {
        memset(dp, -1, sizeof dp);
        int mid=(l+r)/2;
        int aux=ok(mid);
        
        if(~aux) {
			ans=aux;
            best=mid;
            r=mid-1;
        } else l=mid+1;
    }
    
    memset(dp, -1, sizeof dp);
    k-=ans;
    priority_queue<int> pq;
    
    for (int i=0; i<n; i++) {
        v[i]=upd(v[i], best);
        pq.push(v[i]);
    }
    
    while(pq.size() && pq.top() && --k) {
        int x=pq.top();
        pq.pop();
        int h=x-sum(x);
        if(h) pq.push(h);
    }
    
    if(pq.empty()) cout<<"0\n";
    else cout<<sum(pq.top())<<endl;
 
    return 0;
}