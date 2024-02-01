#include <bits/stdc++.h>

using namespace std;

// O reino maluco - OCI 2023

#define MAXN 6
int ans, g[MAXN][MAXN];

int main() {
    for (int i=1; i<=5; i++) {
        for (int j=1; j<=5; j++) {
            int d; cin>>d;
            g[i][j]=g[j][i]=d;
        }
    }
    
    int n;
    vector<int> v;
    while(cin>>n) v.push_back(n);
    
    for (int i=1; i<v.size(); i++) {
        ans+=g[v[i]][v[i-1]];
    }
    
    cout<<ans<<endl;
    
    return 0;
}