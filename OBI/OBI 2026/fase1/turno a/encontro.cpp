#include <bits/stdc++.h>
using namespace std;

int main() {
    int a1,a2,b1,b2,c1,c2;
    cin>>a1>>a2>>b1>>b2>>c1>>c2;

    int cnt=0;
    for(int d=1; d<=31; d++) {
        if(d>=a1&&d>=b1&&d>=c1 && d<=a2&&d<=b2&&d<=c2) {
            cnt++;
        }
    }

    cout<<cnt<<endl;

    return 0;
}