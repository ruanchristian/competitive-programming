#include <bits/stdc++.h>

using namespace std;

#define fastIO ios::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
#define pb push_back
#define MAXN 1000010

int n,k,ans;
bool mark[MAXN], need[MAXN];
vector<int> g[MAXN];

int dfs(int u, int dist) {
    mark[u]=1;

    int r=(need[u] ? dist : 0);

    for(int v:g[u]) {
        if(mark[v]) continue;

        int vv=dfs(v,dist+1);

        if(vv>0) ans+=2;
        r=max(r,vv);
    }

    return r;
}

int main() {
    fastIO
    cin>>n>>k;

    for(int i=1;i<=n;i++) {
        int t; cin>>t;
        if(t>k) need[i]=1;
    }

    for(int i=0;i<n-1;i++) {
        int a,b;
        cin>>a>>b;
        g[a].pb(b);
        g[b].pb(a);
    }
    int maior=dfs(1,0);

    cout<<ans-maior<<endl;

    return 0;
}