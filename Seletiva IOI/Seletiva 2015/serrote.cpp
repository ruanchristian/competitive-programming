#include <bits/stdc++.h>

using namespace std;

const int mxN = 1001;
const int MOD = 1e9+7;

typedef long long ll;

int n, k;
ll dp[mxN][mxN];

// dp[n][k] = qtd de serrotes existentes de tamanho n com k dentes

ll solve(int p, int j) {
    if(p==0 || j<0) return 0;
    if(p<=2 && j==0) return p;
    if(dp[p][j] != -1) return dp[p][j];
    
    dp[p][j]=((2*(j+1)*solve(p-1, j))+solve(p-1, j-1)*(p-2*j))%MOD;
    return dp[p][j];
}

int main() {
    memset(dp, -1, sizeof dp);
    
    cin>>n>>k;
    cout<<solve(n, k)<<endl;
   
    return 0;
}