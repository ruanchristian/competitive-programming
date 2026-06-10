#include <bits/stdc++.h>
using namespace std;
int main() {
	string cod;
	cin>>cod;
	
    string sp="BR-SP";
    int cnt=0;
    for(int i=0;i<5;i++) {
        if(cod[i]==sp[i]) cnt++;
    }
    
    if(cnt==4&&(cod[4]=='?' || cod[3]=='?')) cout<<'T'<<endl;
    else if(cnt==4) cout<<'S'<<endl;
    else cout<<'N'<<endl;

    return 0;
}