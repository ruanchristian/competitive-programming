#include <bits/stdc++.h>
using namespace std;

#define MOD 998244353

int main() {
    int n,k;
    cin>>n>>k;
    
    vector<int> dp(n+1, 0);
    dp[0]=1;
    
    for(int j=1;j<=n;j++) {
        if(j==k) continue;
        
        for(int i=j;i<=n;i++) {
            dp[i]=(dp[i]+dp[i-j])%MOD;
        }
    }
    
    cout<<dp[n]<<endl;

    return 0;
}