#include <bits/stdc++.h>

using namespace std;

#define MAX 101

int L, C, x, y;
int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

char tab[MAX][MAX];
bool visited[MAX][MAX];

bool canGo(int i, int j) {
    return i >= 1 && j >= 1 && i <= L && j <= C && !visited[i][j] && tab[i][j] == 'H';
}

void dfs(int& x, int& y) {
    if (!visited[x][y]) {
        visited[x][y] = 1;
        
        for (int i = 0; i < 4; i++) {
            int dx = x + dirs[i][0];
            int dy = y + dirs[i][1];
            
            if (canGo(dx, dy)) {
                x = dx, y = dy;
                dfs(x, y);
            }
        }
    }
}

int main() {
    cin >> L >> C;
    
    for (int i = 1; i <= L; i++) {
        for (int j = 1; j <= C; j++) {
            cin >> tab[i][j];
            if (tab[i][j] == 'o') {
                x = i;
                y = j;
            }
        }
    }
            
    dfs(x, y); 
    
    cout << x << " " << y << endl;
    
    return 0;
}