#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int n; cin>>n;
    vector<pair<int,int>> v;
    
    for(int i=0; i<n; i++) {
        int in,out;
        cin>>in>>out;
        
        v.push_back({in,1});
        v.push_back({out,-1});
    }
    sort(v.begin(), v.end());
    
    int ans=0, same=0;
    for(auto [t,tipo] : v) {
        same+=tipo;
        ans=max(ans, same);
    }
    cout<<ans<<endl;
}