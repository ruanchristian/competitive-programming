#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
 
const int MAXN = 2*1e5+1;
 
ll vec[MAXN];
 
int main() {
	ll n; cin>>n;
 
    ll tot=0;
    for(int i=1; i<=n; i++) {
        cin>>vec[i];
        tot+=vec[i];
    }
    
    ll nsoma=(n*(n+1))/2;
    
    cout<<nsoma-tot<<endl;
}