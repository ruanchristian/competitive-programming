#include <bits/stdc++.h>

using namespace std;

// Problema: Road Optimization

#define ll long long

int n, l, k;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>n>>l>>k;
    
    vector<ll> d(n);
    vector<int> a(n);
    
    for (int i=0; i<n; i++) cin>>d[i];
    for (int i=0; i<n; i++) cin>>a[i];
    
    d.push_back(l);
    
    vector<vector<ll>> dp(n+1, vector<ll>(k+1, 1e11));
    dp[0][0]=0;
    for (int i=1; i<=n; i++) {
        for (int j=0; j<=k; j++) {
            for (int m=i-1; m>=0 && j-(i-m-1)>=0; m--) {
                dp[i][j]=min(dp[i][j], (d[i]-d[m])*a[m] + dp[m][j-(i-m-1)]);
            }
        }
    }
    
    cout<<*min_element(dp[n].begin(), dp[n].end())<<endl;
    
    return 0;
}