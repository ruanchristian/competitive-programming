#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin>>n;
	
	int v[n];
	for(int i=0;i<n;i++) cin>>v[i];
	
	int ans=0;
	
	for(int i=0;i+1<n;i++) {
	    ans+=abs(v[i]-v[i+1]);
	}
	
	cout<<ans<<endl;
	
	return 0;
}