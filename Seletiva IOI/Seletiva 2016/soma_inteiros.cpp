#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second

typedef long long ll;
typedef pair<ll,ll> pii;
const int mxN = 5*1e5+1;
const ll INF = 1e13;

ll n, k, a[mxN], pref[mxN];
pii dp[mxN];

ll solve() {
    ll l=0, r=INF, mid, auxc=0;
    
    for (int i=0; i<=44; i++) {
        mid=(l+r)>>1;
        pii bst=pii(0,0);
        
        for (int j=1; j<=n; j++) {
            bst=max(bst, pii(dp[j-1].f - pref[j-1], dp[j-1].s));
            dp[j]=max(dp[j-1], pii(bst.f+pref[j]-mid, bst.s+1));
        }
        ll aux=dp[n].s;
        
        if(aux > k) l=mid;
        else if(aux < k) r=mid;
    }
    pii tmp=pii(0,0);
    
    for (int i=1; i<=n; i++) {
        tmp=max(tmp, pii(dp[i-1].f - pref[i-1], dp[i-1].s));
        dp[i]=max(dp[i-1], pii(tmp.f+pref[i]-mid, tmp.s+1));
    }
    
    return mid;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>n>>k;
    
    for (int i=1; i<=n; i++) {
        cin>>a[i];
        pref[i]=pref[i-1]+a[i];
    }
    ll w=solve();
    
    cout<<max(0LL, dp[n].f+k*w)<<endl;
   
    return 0;
}