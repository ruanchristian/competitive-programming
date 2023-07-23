#include <bits/stdc++.h>

using namespace std;

// OBI 2022 - Segunda fase

#define MAXN 35

int N, M, K;
bool vigiado[MAXN][MAXN], vis[MAXN][MAXN];

int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool canGo(int i, int j) {
    return i >= 1 && j >= 1 && i <= N && j <= M && !vis[i][j] && !vigiado[i][j];
}

void BFS(int i, int j) {
    vis[i][j] = 1;
    queue<pair<int, int>> fila;
    fila.push({i, j});
    
    while(fila.size()) {
        int x = fila.front().first;
        int y = fila.front().second;
        fila.pop();
        
        for (int k = 0; k < 4; k++) {
            int dx = x + dirs[k][0];
            int dy = y + dirs[k][1];
            
            if (canGo(dx, dy)) {
                fila.push({dx, dy});
                vis[dx][dy] = 1;
            }
        }
    }
}

int main() {
    cin >> M >> N >> K;
    
    while (K--) {
        int l, c;
        char d;
        cin >> c >> l >> d;
        
        if (d == 'N') {
            for (int i = l; i >= 1; i--) vigiado[i][c] = 1;
        } else if (d == 'L') {
            for (int j = c; j <= M; j++) vigiado[l][j] = 1;
        } else if (d == 'O') {
            for (int j = c; j >= 1; j--) vigiado[l][j] = 1;
        } else {
            for (int i = l; i <= N; i++) vigiado[i][c] = 1;
        }
    }
    
    if (vigiado[1][1] || vigiado[N][M]) {
        cout << "N" << endl;
        return 0;
    }
    
    BFS(1, 1);
    
    if (vis[N][M]) cout << "S" << endl;
    else cout << "N" << endl;
            
    return 0;
}