#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int MAX = 1e5+1;

int n, a, b, v[MAX], seg[4*MAX], dp[MAX*10][30];

int query(int l, int r) {
    if(l==r) return v[l];
    
    int idx=31-__builtin_clz(r-l);
    
    return gcd(dp[l][idx], dp[r-(1<<idx)+1][idx]);
}

ll solve() {
    ll ans=0;
    
    for (int i=1; i<=n; i++) {
        int ret=b;
        
        while(ret>=1) {
            int l=i, r=n, maior1=-1;
            
            while(l<=r) {
                int mid=(l+r)/2;
                
                if(query(i, mid) <= ret) {
                    maior1=mid;
                    r=mid-1;
                } else l=mid+1;
            }
            if(maior1 == -1) break;
            
            int maior2=-1, aux=query(i, maior1);
            l=max(i, maior1), r=n;
            
            while(l<=r && aux) {
                int mid=(l+r)/2;
                
                if(query(i, mid) == aux) {
                    maior2=mid;
                    l=mid+1; 
                } else r=mid-1;
            }
            
            if(a<=aux && aux<=b) {
                ans+=(maior2-maior1+1)*(b-aux+1);
            } else {
                ans+=(maior2-maior1+1)*(b-a+1);
            }
            ret=aux-1;
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>n>>a>>b;
    
    for (int i=1; i<=n; i++) {
        cin>>v[i];
        dp[i][0]=v[i];
    }
    
    for (int j=1; j<=19; j++) {
        for (int i=1; i<=n; i++) {
            dp[i][j]=gcd(dp[i][j-1], dp[i+(1<<(j-1))][j-1]);
        }
    }
    
    cout<<solve()<<endl;
    
    return 0;
}