#include <bits/stdc++.h>

using namespace std;

#define MAXN 101
#define pb push_back
#define INF 0x3f3f3f3f

typedef pair<int, int> pii;

int N, M, S, dist[MAXN];
vector<pii> g[MAXN];

int dijkstra() {
    memset(dist, INF, sizeof dist);
    dist[1] = 0;
    
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, 1});
    while (pq.size()) {
        int d = pq.top().first;
        int v = pq.top().second;
        pq.pop();
        
        if (d > dist[v]) continue;
        
        for (auto u : g[v]) {
            if (dist[u.first] > dist[v] + u.second) {
                dist[u.first] = dist[v]+u.second;
                pq.push({dist[u.first], u.first});
            }
        }
    }
    return dist[N];
}

int main() {
    cin >> N >> M;
    
    while (M--) {
        int u, v, p; cin >> u >> v >> p;
        g[u].pb({v, p});
        g[v].pb({u, p});
    }
    
    cout << dijkstra() << endl;

    return 0;
}