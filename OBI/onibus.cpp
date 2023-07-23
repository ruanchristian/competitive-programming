#include <bits/stdc++.h>

using namespace std;

#define MAXN 10007
#define pb push_back

int N, A, B;
vector<int> g[MAXN];
bool vis[MAXN];

int bfs(int s, int t) {
    queue<pair<int, int>> fila;
    fila.push({s, 0});
    vis[s] = 1;
    
    while (fila.size()) {
        int cidade = fila.front().first;
        int distancia = fila.front().second;
        fila.pop();
        
        if (cidade == t) return distancia;
        
        for (int v : g[cidade]) {
            if (!vis[v]) {
                fila.push({v, distancia+1});
                vis[v] = 1;
            }
        }
    }
    return -1;
}

int main() {
    cin >> N >> A >> B;
    
    for (int i = 0; i < N-1; i++) {
        int u, v; cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    
    cout << bfs(A, B) << endl;

    return 0;
}