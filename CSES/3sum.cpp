#include <bits/stdc++.h>
using namespace std;
 
#define int long long int
#define val first
#define id second
 
signed main() {
	int n,x; 
	cin>>n>>x;
	
	vector<pair<int,int>> v;
	
	for(int i=0; i<n; i++) {
	    int a; cin>>a;
	    v.push_back({a,i+1});
	}
	sort(v.begin(), v.end());
	
	// 1 2 5 7
	for(int k=n-1; k>1; k--) {
	    int l=0, r=k-1;
	    
	    while(l<r) {
	        int soma=v[l].val+v[r].val+v[k].val;
	        
	        if(soma==x) {
	            cout<<v[l].id<<' '<<v[r].id<<' '<<v[k].id<<endl;
	            return;
	        }
	        
	        if(soma > x) r--;
	        else l++;
	    }
	}
	cout<<"IMPOSSIBLE\n";
}