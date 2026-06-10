#include <bits/stdc++.h>
using namespace std;

#define fastIO ios::sync_with_stdio(0); cin.tie(0);
#define endl '\n'

int n,m,p,s;
int adj[22];

int cntbits(int mask, int ini, int fim) {
    int qtd=0;
    
    for(int i=ini; i<=fim; i++) {
        if((mask>>i)&1) qtd++;
    }
    
    return qtd;
}

int main() {
    fastIO

	cin>>n>>m>>p>>s;
	
	while(m--) {
	    int a,b;
	    cin>>a>>b;
	    a--; b--;
	    
	    adj[a]|=(1<<b);
	    adj[b]|=(1<<a);
	}
	
	int ans=0;
	
	for(int mask=0; mask<(1<<n); mask++) {
	    int paes=cntbits(mask, 0, p-1);
	    int sals=cntbits(mask, p, p+s-1);
	    
	    // precisa ter exatamente um pão e uma salsicha no lanche
	    if(paes!=1 || sals!=1) continue;
	    
	    bool valido=1;
	    for(int i=0;i<n && valido;i++) {
	        if((mask>>i)&1 && mask&adj[i]) {
	            valido=0;
	        }
	    }
	    if(valido) ans++;
	}
	
	cout<<ans<<endl;
	
    return 0;
}