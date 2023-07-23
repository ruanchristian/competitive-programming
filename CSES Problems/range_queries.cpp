#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0); cin.tie(nullptr);
    
    int n, q, a, b;
    cin >> n >> q;
    
    ll v[n+1];
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        v[i] += v[i-1];
    }
    
    while (q--) {
        cin >> a >> b;
        
        cout << v[b]-v[a-1] << '\n';
    }
    
    return 0;
}