#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,t;
	cin>>n>>t;
	
	vector<int> tim(n);
	for(int &x:tim) cin>>x;
	
	int ans=0;
	int wait=tim[0]+t;

	for(int i=0;i<n;i++) {
	    if(wait-tim[i]<0) {
	        wait=tim[i]+t;
	        ans++;
	    }
	}
	if(wait>=tim[n-1]) ans++;
	
	cout<<ans<<endl;
	
	return 0;
}