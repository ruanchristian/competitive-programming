#include <bits/stdc++.h>

using namespace std;

// Problema: Parsa's Humongous Tree

#define ll long long
#define all(x) x.begin(), x.end()

const int MAX = 1e5+1;

int n, l, r, v[MAX][2];
ll dp[MAX][2];
vector<int> g[MAX];

void dfs(int u) {
    for (int v : g[u]) {
        g[v].erase(find(all(g[v]), u));
        dfs(v);
    }
    
    for (int k : {0,1}) {
        dp[u][k]=0;
        for (int vertex : g[u]) {
            ll ret=0;
            
            for (int p : {0,1}) {
                ret=max(ret, abs(v[u][k]-v[vertex][p]) + dp[vertex][p]);
            }
            dp[u][k]+=ret;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin>>t;
    
    while(t--) {
        cin>>n;
        
        for (int i=0; i<n; i++) {
            cin>>v[i][0]>>v[i][1]; // [l,r]
            g[i].clear();
        }
        
        for (int i=0; i<n-1; i++) {
            int u, v; cin>>u>>v;
            u--; v--;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        
        dfs(0);
        cout<<max(dp[0][0], dp[0][1])<<'\n';
    }

    return 0;
}