#include <bits/stdc++.h>
using namespace std;

const int MAXN = 801;
int maxtam;
int mat[MAXN][MAXN];

// solução ingênua para a questão 4 O(n³m³)
// 28/100 pontos 

bool check(int linini, int linfim, int colini, int colfim) {
    int last=0;
    maxtam=0;
    bool ok=1;

    for(int i=linini;i<=linfim && ok;i++) {
        for(int j=colini;j<=colfim && ok;j++) {
            if(mat[i][j]-last<=0) {
                ok=0;
                break;
            }
            last=mat[i][j];
            maxtam++;
        }
    }

    return ok;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    int n,m; cin>>n>>m;

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            cin>>mat[i][j];
        }
    }

    int ans=0;
    for(int lin1=1;lin1<=n;lin1++) {
        for(int lin2=lin1;lin2<=n;lin2++) {
            for(int col1=1;col1<=m;col1++) {
                for(int col2=col1;col2<=m;col2++) {
                    if(check(lin1, lin2, col1, col2)) {
                        ans=max(ans, maxtam);
                    }
                }
            }
        }
    }

    cout<<ans<<'\n';

    return 0;
}