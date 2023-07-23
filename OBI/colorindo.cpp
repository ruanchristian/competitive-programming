#include <bits/stdc++.h>

using namespace std;

// OBI 2011

#define MAXN 201

int N, M, X, Y, K, resp, grid[MAXN][MAXN];

int dirs[8][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

bool canPaint(int i, int j) {
    return i >= 1 && j >= 1 && i <= N && j <= M && grid[i][j] == -1;
}

void bfs(int i, int j) {
    queue<pair<int, int>> fila;
    fila.push({i, j});
    
    while (fila.size()) {
        int x = fila.front().first;
        int y = fila.front().second;
        fila.pop();
        
        if (grid[x][y] == -1) {
            grid[x][y] = 0;
            resp++;
            
            for (int k = 0; k < 8; k++) {
                int dx = x + dirs[k][0];
                int dy = y + dirs[k][1];
            
                if (canPaint(dx, dy)) fila.push({dx, dy});
            }
        }
    }
}

int main() {
    cin >> N >> M >> X >> Y >> K;
    
    for (int i=1; i<=N; i++)
        for (int j=1; j<=M; j++)
            grid[i][j] = -1;
    
    while (K--) {
        int a, b; cin >> a >> b;
        grid[a][b]=1;
    }
    
    bfs(X, Y);
    cout << resp << endl;

    return 0;
}