#include <bits/stdc++.h>

#define MAXN 55

using namespace std;

// OBI 2024 Fase 1 - Questão 4 (Jogo da vida)

int n, q, dirs[8][2]={{0,1}, {1,0}, {0,-1}, {-1,0}, {1,1}, {-1,-1}, {-1,1}, {1,-1}};

char grafo[MAXN][MAXN], auxiliar[MAXN][MAXN];

bool inside(int i, int j) {
    return i>0 && i<=n && j>0 && j<=n;
}

void solve() {
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            // contagem das celulas vizinhas vivas...
            int vivos=0;
            for (int k=0; k<8; k++) {
                int dx=dirs[k][0]+i;
                int dy=dirs[k][1]+j;
                
                if(inside(dx, dy) && grafo[dx][dy]=='1') vivos++;
            }
            auxiliar[i][j]=grafo[i][j];
            
            if(vivos==3 && grafo[i][j]=='0') auxiliar[i][j]='1';
            if((vivos>3 || vivos<2) && grafo[i][j]=='1') auxiliar[i][j]='0';
        }
    }
    
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            grafo[i][j]=auxiliar[i][j];
        }
    }
}

int main() {
    cin>>n>>q;
    
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cin>>grafo[i][j];
        }
    }
    
    while(q--) solve();
    
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cout<<grafo[i][j];
        }
        cout<<'\n';
    }
    
    return 0;
}