#include <bits/stdc++.h>

using namespace std;

// Criptografia divertida - OCI 2023

int n;
string in, cod, cryp, alfa="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
unordered_map<char, int> mp;

int main() {
    cin>>n>>in>>cod;
    
    for (int i=0; i<26; i++) mp[alfa[i]]=i;
    
    for (char c : in) cryp+=alfa[(mp[c]+n)%26];
    
    cout<<(cryp==cod ? "SIM" : "NAO")<<endl;

    return 0;
}