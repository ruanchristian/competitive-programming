#include <bits/stdc++.h>

using namespace std;

// Amor nos números - OCI 2023

typedef long long ll;

int p;

ll mul(ll a, ll b, ll m) {
    ll res = a*b-ll((long double)1/m*a*b+0.5)*m;
    return res<0 ? res+m : res;
}

ll pow(ll x, ll y, ll m) {
    if(!y) return 1;
    ll ans=pow(mul(x, x, m), y/2, m);
    return y%2 ? mul(x, ans, m) : ans;
}

bool eh_primo(ll n) {
    if (n<2) return 0;
    if (n<=3) return 1;
    if (n%2==0) return 0;
    
    ll r = __builtin_ctzll(n-1);
    ll d=(n>>r);
    
    for (int a : {2, 325, 9375, 28178, 450775, 9780504, 1795265022}) {
        ll x = pow(a, d, n);
        if (x==1 || x==n-1 || a%n==0) continue;
        
        for (ll j=0; j<r-1; j++) {
            x=mul(x, x, n);
            if (x==n-1) break;
        }
        if (x!=n-1) return 0;
    }
    return 1;
}

int main() {
    ll nn1, nn2; cin>>nn1>>nn2;
    string n1=to_string(nn1);
    string n2=to_string(nn2);
    
    int sa=n1.size(), sb=n2.size();
    
    if(nn1==nn2) {
        cout<<"100\n"<<endl;
        return 0;
    }
    
    if(n1[0]==n2[0]) p+=20;
    if(eh_primo(nn1) && eh_primo(nn2)) p+=30;
    
    int imparA=0, imparB=0;
    
    for (int i=0; i<sa; i++) {
        if((n1[i]-'0')&1) imparA++;
    }
    
    for (int i=0; i<sb; i++) {
        if((n2[i]-'0')&1) imparB++;
    }
    
    if(imparA==imparB) p+=30;
    int ultiA=nn1%10, ultiB=nn2%10;
    
    if((ultiA%2==0 && ultiB%2==0) || (ultiA&1 && ultiB&1)) p+=20;
    if((ultiA%2==0 && ultiB&1) || (ultiA&1 && ultiB%2==0)) p-=10;
    
    cout<<max(0, p)<<endl;
    
    return 0;
}