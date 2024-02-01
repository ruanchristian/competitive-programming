#include <bits/stdc++.h>

using namespace std;

// Investimento virtual - OCI 2023

double v, t, c, seguro, arriscado;

// t = taxa cobrada na opção arriscada

int main() {
    cin>>v>>t>>c;
    c/=100;
    
    int ans=0;
    
    seguro=v, arriscado=v-t;
    while(arriscado<=seguro) {
        seguro=seguro*(1+c);
        arriscado=arriscado*(1+(c*1.5));
        ans++;
    }
    
    cout<<ans<<endl;
    
    return 0;
}