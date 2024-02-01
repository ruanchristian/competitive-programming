#include <bits/stdc++.h>

using namespace std;

string px[3];

int somaL(int x) {
    int sum=0;
    for(int j=0; j<3; j++) {
        if(px[x][j]=='?') continue;
        sum+=int(px[x][j]);
    }
    
    return sum;
}

int main() {
    int t; cin>>t;
    while(t--) {
        for(int i=0; i<3; i++) cin>>px[i];
        
        int ax=-1;
        bool flag=false;
        for(int i=0; i<3; i++) {
            if(flag) break;
            for(int j=0; j<3; j++) {
                if(px[i][j]=='?') {
                    ax=somaL(i);
                    flag=true;
                    break;
                }
            }
        }
        cout<<char(198-ax)<<'\n';
    }
   
    return 0;
}