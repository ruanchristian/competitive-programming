#include <bits/stdc++.h>
using namespace std;
 
#define ll long long int
 
int main() {
    int n; cin>>n;
    
    vector<ll> m(n); // maçãs
    
    for(int i=0; i<n; i++) cin>>m[i];
    
    ll ans=LLONG_MAX;
    for(int mask=1; mask < (1<<n); mask++) {
        ll soma1=0, soma2=0;
        
        for(int i=0; i<n; i++) {
            // se o bit i da mask tiver setado (1), a fruta vai pro grupo 1
            if((mask>>i) & 1) soma1+=m[i];
            else soma2+=m[i];
        }
        
        ans=min(ans, abs(soma1-soma2));
    }
    
    cout<<ans<<endl;
}