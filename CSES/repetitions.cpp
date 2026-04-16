#include <bits/stdc++.h>
using namespace std;
 
int main() {
    string s;
    cin>>s;
    
    int curr=0, maxfreq=-1;
    char ultimo='\0';
    
    for(char ch : s) {
        if(ch==ultimo) {
            curr++;
        } else {
            if(curr>maxfreq) maxfreq=curr;
            
            curr=1;
            ultimo=ch;
        }
    }
    if(curr > maxfreq) maxfreq=curr;
    
    cout<<maxfreq<<endl;
    
    return 0;
}