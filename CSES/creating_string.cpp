#include <bits/stdc++.h>
using namespace std;
 
int fatorial(int x) {
    if(x==0) return 1;
    
    return x*fatorial(x-1);
}
 
int main() {
    string s;
    cin>>s;
    sort(s.begin(), s.end());
    
    int k=1, n=s.size();
    map<char,int> mpfreq;
    
    for(char ch:s) mpfreq[ch]++;
    for(char c='a'; c<='z'; c++) k*=fatorial(mpfreq[c]);
    
    cout<<fatorial(n)/k<<endl;
    do{
        cout<<s<<endl;
    } while(next_permutation(s.begin(), s.end()));
    
    
    return 0;
}