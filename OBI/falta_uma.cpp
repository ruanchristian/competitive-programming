#include <bits/stdc++.h>

using namespace std;

// OBI 2016 - Segunda fase

int fact(int x) {
    if (x==1) return x;
    
    return x*fact(x-1);
}

int main() {
    int n;
    cin >> n;
    
    int nFatorial = fact(n);
    
    string ans, aux;
    unordered_set<string> perms;
    for (int i = 0; i < nFatorial-1; i++) {
        int temp = 0;
        aux = "";
        
        for (int j = 0; j < n; j++) {
            cin >> temp;
            aux += to_string(temp);
        }
        perms.insert(aux);
    }
    
    vector<int> v(n);
    for (int i = 0; i < n; i++) v[i] = i+1;
    
    do {
        aux = "";
        for (int x : v) aux += to_string(x);
        
        if (!perms.count(aux)) {
            ans = aux;
            break;
        }
        
    } while(next_permutation(v.begin(), v.end()));
    
    for (char ch : ans) cout << ch << " ";
    
    return 0;
}