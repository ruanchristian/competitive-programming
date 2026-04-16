#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
 
int main() {
	int n; cin>>n;
	
	vector<ll> vec(n);
	set<ll> st;
	
	for(int i=0; i<n; i++) cin>>vec[i];
	
	int l=0, r=0, ans=0;
	while(r<n) {
	    if(!st.count(vec[r])) {
	        st.insert(vec[r]);
	        ans=max(ans, r-l+1);
	        r++;
	    } else {
	        st.erase(vec[l]);
	        l++;
	    }
	}

	cout<<ans<<endl;
	
	return 0;
}