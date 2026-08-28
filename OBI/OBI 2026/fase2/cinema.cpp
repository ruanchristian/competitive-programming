#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005

int qtd[MAXN]; // qtd[i] = qtd de pessoa na sessão i.
int capsessao[MAXN]; // capsessao[i] = capacidade de pessoas na sessao i.
int p[MAXN]; // p[i] = instante em que a pessoa i comprou o ingresso
int hs[MAXN]; // hs[i] = horario de inicio da sessao i

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m,c;
    cin>>n>>m>>c;
    
    for(int i=1;i<=n;i++) cin>>p[i];
    for(int i=1;i<=m;i++) cin>>hs[i];
    for(int i=1;i<=m;i++) capsessao[i]=c;

    // two pointer
    int r=1;
    for(int l=1;l<=m;l++) {
        while(r<=n && p[r]<=hs[l] && capsessao[l]>0) {
            qtd[l]++;
            capsessao[l]--;
            r++;
        }
    }

    for(int i=1;i<=m;i++) cout<<qtd[i]<<' ';

    return 0;
}