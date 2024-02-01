#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

void solve() {
    ll n, k; cin>>n>>k;
    
    ll l=1, r=k*n, mid;
    while(l<=r) {
        mid=(l+r)>>1;
        if(mid%n==0) mid++;
        
        if(mid-(mid/n)==k) {
            cout<<mid<<'\n';
            return;
        } else if(mid-(mid/n)<k) {
            l=mid;
        } else {
            r=mid;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int tt; cin>>tt;
    while(tt--) {
        solve();
    }

    return 0;
}