#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005

int soma[MAXN];
vector<int> fi[MAXN];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,f;
    cin>>n>>f;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q; // pesos
    for(int i=1;i<=f;i++) {
        q.push({0,i}); // peso -> num da fila
    }

    for(int i=1;i<=n;i++) {
        int p; cin>>p;

        auto [peso,num]=q.top();
        q.pop();
        fi[num].push_back(p);
        soma[num]+=p;
        q.push({soma[num], num});
    }

    for(int i=1;i<=f;i++){
        for(int x:fi[i]) {
            cout<<x<<' ';
        }
        cout<<'\n';
    }

    return 0;
}