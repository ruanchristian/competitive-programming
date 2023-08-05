#include <bits/stdc++.h>

using namespace std;

#define MAXN 1001

int n, m;
char lab[MAXN][MAXN];
bool visited[MAXN][MAXN];

int dirs[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

bool canGo(int i, int j) {
    return i >= 1 && j >= 1 && i <= n && j <= m && !visited[i][j] && lab[i][j] == '.';
}

void dfs(int x, int y) {
    if (!canGo(x, y)) return;
    
    visited[x][y] = 1;
    
    for (int i = 0; i < 4; i++) {
        int dx = x + dirs[i][0];
        int dy = y + dirs[i][1];
        
        dfs(dx, dy);
    }
}

int main() {
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> lab[i][j];
            
    int ans=0;        
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (!visited[i][j] && lab[i][j] == '.') {
                dfs(i, j);
                ans++;
            }
        }
    }        
    cout << ans << endl;
    
    return 0;
}