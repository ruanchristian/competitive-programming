#include <bits/stdc++.h>
using namespace std;
 
#define int long long int
#define pb push_back
 
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
	int n; cin>>n;
 
    int tot=n*(n+1)/2; // soma de 1 a n...
    
    if(tot&1) cout<<"NO\n"; // se n é impar nao dá pra dividir em dois sets de mesma soma
    else {
        cout<<"YES\n";
        
        vector<int> v1,v2;
        vector<bool> marcado(n+1, 0);
        
        int soma1=0, x=n;
        while(soma1 < tot/2) {
            int diff = (tot/2)-soma1;
            
            if(diff > x) {
                v1.pb(x);
                marcado[x]=1;
                soma1+=x;
                x--;
            } else {
                v1.pb(diff);
                marcado[diff]=1;
                break;
            }
        }
        // seleciona os elementos do outro conjunto
        for(int i=1; i<=n; i++) {
            if(!marcado[i]) v2.pb(i);
        }
        
        cout<<v1.size()<<'\n';
        for(int k:v1) cout<<k<<' ';
        cout<<'\n';
        
        cout<<v2.size()<<'\n';
        for(int x:v2) cout<<x<<' ';
    }
}