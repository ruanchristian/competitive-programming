#include <bits/stdc++.h>

using namespace std;

// OBI 2017

#define MAX 107

int N, dp[MAX][MAX];

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++) 
            cin >> dp[i][j];
    
    for (int i=2; i<=N; i++) {
        for (int j=2; j<=N; j++) {
            if (dp[i][j-1]+dp[i-1][j]+dp[i-1][j-1] > 1) dp[i][j]=0;
            else dp[i][j]=1;
        }
    }
    
    cout << dp[N][N] << endl;

    return 0;
}