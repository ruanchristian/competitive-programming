#include <bits/stdc++.h>

using namespace std;

#define sec 100

typedef long long ll;

vector<vector<ll>> dp;

ll safe_gcd(int l, int r) {
    int k=31-__builtin_clz(r-l);
    return gcd(dp[l][k], dp[r-(1<<k)][k]);
}

void solve() {
    int n, ans=1;
    cin>>n;
    vector<ll> v(n);
    
    for (int i=0; i<n; i++) cin>>v[i];
    
    if(n==1) {
        cout<<"1\n";
        return;
    }
    
    int m=31-__builtin_clz(n);
    dp.resize(n+sec, vector<ll>(m+sec, 0));
    
    for (int i=1; i<n; i++) dp[i][0]=abs(v[i]-v[i-1]);
    
    for (int k=0, j=1; k<m; k++, j<<=1) {
        for (int i=1; (i+j)<n; i++) {
            dp[i][k+1]=gcd(dp[i][k], dp[i+j][k]);
        }
    }
    
    for (int i=1, j=1; i<n; i++) {
        while(j<=i && safe_gcd(j, i+1)==1) {
            j++;
        }
        ans=max(ans, i-j+2);
    }
    
    cout<<ans<<'\n';
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