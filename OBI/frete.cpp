#include <bits/stdc++.h>

using namespace std;

// OBI 2017 - Segunda fase

#define INF 0x3f3f3f3f

int n, m, dp[1001][1001];

void floyd_warshall() {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = min(dp[i][j], dp[i][k]+dp[k][j]);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(nullptr);

    cin >> n >> m;
    
    memset(dp, INF, sizeof dp);
    
    while (m--) {
        int u, v, w; cin >> u >> v >> w;
        dp[u][v] = dp[v][u] = w;
    }
    floyd_warshall();
    
    cout << dp[1][n] << endl;

    return 0;
}