#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef tuple<ll,ll,ll> tii;
typedef pair<ll,ll> pii;

const int mxN = 1e4+1;
const ll MAX = 1e9;

ll n, m, ans=2*MAX;
vector<ll> dist;
vector<pii> g[mxN];

vector<ll> bfs() {
    queue<ll> q;
    bool vis[mxN]={};
    vector<ll> dst(n+1);
    
    q.push(1);
    vis[1]=true;
    while(q.size()) {
        ll u=q.front(); q.pop();
        for (auto [w,v] : g[u]) {
            if(!vis[v]) {
                dst[v]=dst[u]+1;
                vis[v]=true;
                q.push(v);
            }
        }
    }
    return dst;
}

bool chk(int k) {
    bool vis[mxN]={};
    ll d1[mxN]={}, d2[mxN]={};
    priority_queue<tii, vector<tii>, greater<tii>> pq;
    pq.push({0,0,1});
    
    while(pq.size()) {
        auto [dist, tot, u]=pq.top();
        pq.pop();

        if(vis[u]) continue;
        vis[u]=1;
        
        d1[u]=dist;
        d2[u]=tot;
        
        for(auto [w,v] : g[u]) {
            if(!vis[v]) {
                pq.push({d1[u]+k+w, tot+1, v});
            }
        }
    }
    for (int i=1; i<=n; i++) {
        if(d2[i]!=dist[i]) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>n>>m;
    while(m--) {
        int a, b, c; cin>>a>>b>>c;
        g[a].push_back({c, b});
        g[b].push_back({c, a});
    }

    dist=bfs();
    
    ll l=0, r=2*MAX;
    
    while(l<=r) {
        ll mid=(l+r)/2;
        if(chk(mid)) {
            ans=mid;
            r=mid-1;
        } else l=mid+1;
    }
    
    cout<<ans<<endl;
    
    return 0;
}