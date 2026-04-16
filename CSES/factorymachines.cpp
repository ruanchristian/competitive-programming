#include <bits/stdc++.h>
using namespace std;
 
#define int unsigned long long int
#define INF 0x3f3f3f3f3f3f3f3f
 
const int MAXN = 2*1e5+1;
 
int n,t;
int crono[MAXN];
 
int sumitems(int t) {
    int s=0;
    
    for(int i=1; i<=n; i++) {
        s+=(t/crono[i]);
    }
    
    return s; // qtd de items
}
 
signed main() {
	cin>>n>>t;
 
    for(int i=1; i<=n; i++) cin>>crono[i];
    
    //minimizar o tempo pra produzir ao menos t items
	
	int resp=0;
	int l=1, r=INF;
	while(l<=r) {
	    int med=(l+r)/2;
	    
	    if(sumitems(med) >= t) {
	        resp=med;
	        r=med-1;
	    } else {
	        l=med+1;
	    }
	}
	cout<<resp<<endl;
}