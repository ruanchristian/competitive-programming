#include <bits/stdc++.h>

using namespace std;

#define fastIO ios::sync_with_stdio(0); cin.tie(0);
#define endl '\n'

int main() {
    fastIO

    int n; cin>>n;
    while(n--) {
        int x,y;
        cin>>x>>y;
        if((x+y-100<=0 && x-y-200<=0 && y+100>=0 && x+y+100>=0 && x-y+200>=0 && y-100<=0) || (y>=0 && x+y+100<=0 && x-y+200>=0) || (y<=0 && x+y-100>=0 && x-y-200<=0))
        cout<<"S"<<'\n';
        else cout<<"N"<<endl;
    }

    return 0;
}