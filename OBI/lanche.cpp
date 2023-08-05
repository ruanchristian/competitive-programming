#include <bits/stdc++.h>

using namespace std;

#define MAXN 251

int S, C, dist[MAXN][MAXN];

void floyd() {
    for (int k=1; k<=S; k++)
        for (int i=1; i<=S; i++)
            for (int j=1; j<=S; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}

int main() {
    cin >> S >> C;
    memset(dist, 0x3f, sizeof dist);
    
    for (int i=1; i<=S; i++) dist[i][i]=0;
    
    while (C--) {
        int A, B, D; cin >> A >> B >> D;
        dist[A][B] = dist[B][A] = D;
    }
    floyd();
    
    int ans = INT_MAX;
    for (int i = 1; i <= S; i++) {
        int mx = 0;
        for (int j = 1; j <= S; j++) mx = max(mx, dist[i][j]);
        ans = min(ans, mx);
    }
    cout << ans << endl;

    return 0;
}