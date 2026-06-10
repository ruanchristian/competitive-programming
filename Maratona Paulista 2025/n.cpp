#include <bits/stdc++.h>

using namespace std;

#define fastIO ios::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
#define pb push_back
#define MAXN 1000007

int n;
bool estado[MAXN];
int on[MAXN]; // on[k] = qtd de luzes acesas pro pulo de tamanho k
multiset<int> highk;

void att(int x, int val) {
    for(int i=1;i<=x/i;i++) {
        if(x%i==0) {
            int d1=i;
            int d2=x/i;

            if(d1>1) {
                auto it=highk.find(on[d1]);
                if(it!=highk.end()) highk.erase(it);

                on[d1]+=val;
                highk.insert(on[d1]);
            }
            if(d2>1 && d2!=d1) {
                auto it=highk.find(on[d2]);
                if(it!=highk.end()) highk.erase(it);

                on[d2]+=val;
                highk.insert(on[d2]);
            }
        }
    }
}

int main() {
    fastIO

    cin>>n;

    int l,r=0;
    for(int i=1;i<=n;i++) {
        int x;cin>>x;
        
        estado[x]=!estado[x];

        if(estado[x]) att(x,1);
        else att(x,-1);

        cout<<*(highk.rbegin())<<endl;
    }
    return 0;
}