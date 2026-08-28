#include <bits/stdc++.h>
using namespace std;

int main() {
    int a,b,p;
    cin>>a>>b>>p;

    int dista=abs(a-p);
    int distb=abs(b-p);

    if(dista<distb) cout<<"A\n";
    else if(distb<dista) cout<<"B\n";
    else cout<<"E\n";

    return 0;
}