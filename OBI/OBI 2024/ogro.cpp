#include <bits/stdc++.h>

using namespace std;

// OBI 2024 Fase 1 - Questão 1 (Ogros)

int main() {
    int e, d;
    cin>>e>>d;
    
    if(e>d) cout<<(e+d)<<endl;
    else cout<<2*(d-e)<<endl;

    return 0;
}