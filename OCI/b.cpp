#include <bits/stdc++.h>

using namespace std;

// Patrimônio - OCI 2023

int n;
double ans;

int main() {
    cin>>n;
    vector<int> quant(n);
    vector<double> val(n);
    
    for (int i=0; i<n; i++) cin>>quant[i];
    for (int i=0; i<n; i++) cin>>val[i];
    
    for (int i=0; i<n; i++) ans+=quant[i]*val[i];
    
    cout<<ans<<endl;

    return 0;
}