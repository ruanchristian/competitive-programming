#include <bits/stdc++.h>

using namespace std;

// Ferias cansativas - SBC

int d, c, r, ans;
queue<int> cansativas, rev;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>d>>c>>r;
  
    for (int i=0; i<c; ++i) {
        int v; cin>>v;
        cansativas.push(v);
    }
    for (int i=0; i<r; ++i) {
        int v; cin>>v;
        rev.push(v);
    }
    
    while(!cansativas.empty()) {
        int atvc=cansativas.front();
        
        if (d>=atvc) {
            d-=atvc;
            ans++;
            cansativas.pop();
        } else {
            if(rev.empty()) {
                cout<<ans<<endl;
                return 0;
            }
            
            while (d<cansativas.front() && !rev.empty()) {
                d+=rev.front();
                ans++;
                rev.pop();
            }
        }
    }
    
    while(!rev.empty()) {
        ans++;
        rev.pop();
    }
    
    cout<<ans<<endl;
    
    return 0;
}