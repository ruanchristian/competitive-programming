#include <bits/stdc++.h>

#define MAXN 501

using namespace std;

// OBI 2024 Fase 1 - Questão 3 (Concurso)

int v[MAXN];

int main() {
    int n, k;
    cin>>n>>k;
    
    for (int i=0; i<n; i++) cin>>v[i];
    sort(v, v+n, greater<int>());
    
    cout<<v[k-1]<<endl;
    
    return 0;
}