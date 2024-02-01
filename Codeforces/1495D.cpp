#include <bits/stdc++.h>

using namespace std;

// Problema: BFS Trees

#define MOD 998244353
#define ll long long

const int MAX = 401;

int n, m, dist[MAX][MAX];
ll dp[MAX][MAX];
vector<int> g[MAX];

void floyd() {
    for (int k=1; k<=n; k++) {
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                dist[i][j]=min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }
}

void solve() {
    for (int u=1; u<=n; u++) {
        for (int v=1; v<=n; v++) {
            int aux=0;
            for (int k=1; k<=n; k++) {
                aux+=(dist[u][v] == dist[u][k]+dist[k][v]);
            }
            if(aux != dist[u][v]+1) continue;

            dp[u][v]=1;
            for (int k=1; k<=n; k++) {
                if(dist[u][v] == dist[u][k]+dist[k][v]) continue;
                aux=0;
                for (int vert : g[k]) {
                    aux+=(dist[u][k] == dist[u][vert]+1 && dist[v][k] == dist[v][vert]+1);
                }
                dp[u][v]=dp[u][v]*aux%MOD;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>n>>m;
    
    while(m--) {
        int u, v; cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            dist[i][j]=MAX;
        }
    }
    
    for (int u=1; u<=n; u++) {
        for (int v : g[u]) {
            dist[u][v]=1;
        }
    }
    
    // dist de um vertice pra ele mesmo é 0
    for (int i=1; i<=n; i++) dist[i][i]=0;
    
    floyd();
    solve();
    
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cout<<dp[i][j]<<' ';
        }
        cout<<'\n';
    }

    return 0;
}