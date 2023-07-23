#include <bits/stdc++.h>

// Soma de Prefixo

using namespace std;

#define MAXN 10000

int v[MAXN];
long long prefix[MAXN];

int main() {
    int n, q;
    cin >> n >> q;
    
    for (int i = 1; i <= n; i++) cin >> v[i];
    
    // Calculando somas de prefixo
    prefix[1] = v[1];
    
    for (int i = 2; i <= n; i++)
        prefix[i] = prefix[i-1] + v[i];
        
    
    // prefix[r] = v[1] + v[2] + ... + v[r] == (v[1] + v[2] + ... + v[l-1]) + (v[l] + v[l+1] + ... + v[r])    
    // v[1] + v[2] + ... + v[l-1] == prefix[l-1]
    // prefix[r] = prefix[l-1] + v[l] + v[l+1] + ... + v[r]
    // v[l] + v[l+1] + ... + v[r] == prefix[r] - prefix[l-1]
    
        
    while (q--) {
        // Soma no intervalo [L, R]
        int l, r;
        cin >> l >> r;
        
        cout << prefix[r] - prefix[l-1] << endl;
    }    

    return 0;
}
