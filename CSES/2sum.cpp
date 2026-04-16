#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
 
int main() {
	int n, x;
	cin>>n>>x;
	
	vector<ll> v(n);
	for(int i=0; i<n; i++) cin>>v[i];
	
	map<ll,int> mp; // complemento -> indice
	
	for(int i=0; i<n; i++) {
	    if(mp[v[i]]) {
	        cout<<mp[v[i]]<<' '<<(i+1)<<endl;
	        return 0;
	    } else {
	        mp[x-v[i]]=i+1;
	    }
	}
	
	cout<<"IMPOSSIBLE\n";
}