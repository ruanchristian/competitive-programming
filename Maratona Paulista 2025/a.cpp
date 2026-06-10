#include <bits/stdc++.h>

using namespace std;

#define fastIO ios::sync_with_stdio(0); cin.tie(0);
#define endl '\n'

int main() {
    int w,a,b,c;
    cin>>w>>a>>b>>c;

    if(a+b+c<=w) cout<<"S"<<endl;
    else cout<<"N"<<endl;

    return 0;
}