#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
signed main() {
    int n; cin>>n;
    
    int ans=-1e15, soma=-1e15;
    for(int i=0; i<n; i++) {
        int x; cin>>x;
        
        soma=max(soma+x, x);
        ans=max(ans, soma);
    }
    cout<<ans<<endl;
}