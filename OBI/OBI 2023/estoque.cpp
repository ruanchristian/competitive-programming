#include <bits/stdc++.h>

using namespace std;

int main() {
    int M, N, P, ans=0;
    cin >> M >> N;
    
    int estq[M+1][N+1];
    
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) cin >> estq[i][j];
    }
    cin >> P;
    
    while(P--) {
        int x, y;
        cin >> x >> y;
        
        if (estq[x][y] == 0) continue;
        
        estq[x][y]--; ans++;
    }
    
    cout << ans << endl;
    
    return 0;
}