#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f
#define MAXN 10002
#define MAXK 3002

typedef long long ll;

int n, k, a[MAXN];
ll dp[MAXN][MAXK];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>k;
    
    for(int i=1; i<=n; i++) cin>>a[i];
    sort(a+1, a+1+n, greater<int>());
    
    dp[1][0]=0;
    for (int v=1; v<=k; v++) dp[1][v]=INF;
    
    for(int i=2; i <= n; i++) {
        for(int j=0; j<=k; j++) {
            if (3*j > i) dp[i][j]=INF;
            else {
                // minimum god balanceamento de bonecas ok
                int diff=a[i]-a[i-1];
                dp[i][j] = min(dp[i-1][j], dp[i-2][j-1] + diff*diff);
            }
        }
    }
    cout<<dp[n][k]<<endl;
}