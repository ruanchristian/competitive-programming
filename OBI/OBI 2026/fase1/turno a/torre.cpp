#include <bits/stdc++.h>
using namespace std;

int main() {
    string n;
    cin>>n;

    set<string> mark;
    mark.insert(n);

    while(1){
        cout<<n<<endl;

        int x=stoi(n);

        while(log10(x)+1<4) {
            x*=10;
        }

        string x1="",x2="";
        while(x>0) {
            x1+=to_string(x%10);
            x/=10;
        }
        x2=x1;
        sort(x1.begin(), x1.end());
        sort(x2.rbegin(), x2.rend());

        int posres=stoi(x2)-stoi(x1);
        if(mark.count(to_string(posres))) break;

        mark.insert(to_string(posres));
        n=to_string(posres);
    }

    return 0;
}