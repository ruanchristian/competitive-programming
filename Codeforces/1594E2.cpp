#include <bits/stdc++.h>

using namespace std;

// Problema: Rubik's Cube Coloring (hard version)

#define ll long long
#define arr array<int, 6>

const int MOD = 1e9+7;

int k, n, ans;
arr dp={1,1,1,1,1,1};

vector<vector<pair<ll, int>>> grafo;
map<char,int> mp = {{'w',0}, {'y',1}, {'g',2}, {'b',3}, {'r',4}, {'o',5}};
map<ll, arr> pd;

int mulmod(ll x, int y) {
    return x*y%MOD;
}

void safe_plus(int &a, int v) {
    a+=v;
    if(a>=MOD) a-=MOD;
}

arr operator*(arr u, arr v) {
    arr resp;
    for (int i=0; i<6; i++) {
        int a=0, b=0;
        for (int j=0; j<6; j++) {
            if((i^j) >= 2) {
                safe_plus(a, u[j]);
                safe_plus(b, v[j]);
            }
        }
        resp[i]=mulmod(a, b);
    }
    return resp;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>k>>n;
    grafo.resize(k);
    
    for (int i=0; i<n; i++) {
        ll v; 
        string s;
        cin>>v>>s;
        
        int idx=63-__builtin_clzll(v);
        
        grafo[idx].push_back({v, mp.at(s[0])});
    }
    
    for (auto [i, j] : grafo[k-1]) {
        pd[i]={0, 0, 0, 0, 0, 0};
        pd[i][j]=1;
    }
    
    for(int i=k-2; i>=0; --i) {
        map<ll, arr> pd2;
        for (auto [x, y] : pd) {
            auto it=pd.find(x^1);
            
            if(it==pd.end()) {
                pd2[x>>1]=y*dp;
            } else if(x&1) {
                pd2[x>>1]=y*it->second;
            }
        }
        dp=dp*dp;
        
        for (auto [u, v] : grafo[i]) {
            auto it=pd2.find(u);
            
            if(it==pd2.end()) {
                tie(it, ignore)=pd2.insert({u, dp});
            }
            for (int w=0; w<6; w++) {
                if(w!=v) {
                    (it->second)[w]=0;
                }
            }
        }
        pd=move(pd2);
    }
    
    for (int x : pd[1]) safe_plus(ans, x);
    
    cout<<ans<<endl;
    
    return 0;
}