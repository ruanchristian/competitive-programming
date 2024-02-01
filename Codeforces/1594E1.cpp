#include <bits/stdc++.h>

using namespace std;

// Problema: Rubik's Cube Coloring (easy version)

#define ll long long

const int MOD = 1e9+7;

int k;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>k;
    
    ll ans=1;
    for(int i=0; i<k-1; i++) {
        ans=(16*ans%MOD*ans)%MOD;
    }
    
    cout<<(ans*6) % MOD<<endl;
    
    return 0;
}