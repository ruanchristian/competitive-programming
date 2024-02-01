#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin>>t;
    while(t--) {
        int w[3]={};
        cin>>w[0]>>w[1]>>w[2];
        
        int ans=0;
        for (int x:w) ans^=x;
        
        cout<<ans<<'\n';
    }
   
    return 0;
}