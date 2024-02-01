#include<bits/stdc++.h>

using namespace std;

#define inf 0x3f3f3f3f3f3f
#define ll long long

const int MAXN = 1e5+1;

int n, k;
ll v[MAXN], pref[MAXN], dp[MAXN][4];

ll solve(int i, int cnt) {
    if(cnt==3) return 0;
    if(i>n) return -inf;
    if(dp[i][cnt]!=-1) return dp[i][cnt];
    
    if(cnt==1) dp[i][cnt]=max(solve(i+k, 2)+pref[i]-pref[i-k], solve(i+1, 1));
    else dp[i][cnt]=max(solve(i+k, 3)+pref[i]-pref[i-k], solve(i+1, 2));
    
    return dp[i][cnt];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>n>>k;
    
    memset(dp, -1, sizeof dp);
    
    for (int i=1; i<=n; i++) {
        cin>>v[i];
        v[i]=v[i]*-1;
        pref[i]=pref[i-1]+v[i];
    }
    
    cout<<solve(k, 1)<<endl;

    return 0;
}