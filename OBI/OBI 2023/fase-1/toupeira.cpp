#include <bits/stdc++.h>

using namespace std;

#define MAXN 1007

int S, T, P, ans = 0, c[MAXN];
bool adj[MAXN][MAXN];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> S >> T;
    while(T--) {
        int a, b;
        cin >> a >> b;
        adj[a][b] = adj[b][a] = 1;
    }
    cin >> P;

    while(P--) {
        int N;
        cin >> N;
        for (int i=0; i<N; i++) cin >> c[i];

        bool ok = 1;
        for (int k=1; k<N; k++) {
            if (!adj[c[k]][c[k-1]]) {
                ok = 0;
                break;
            }
        }
        if(ok) ans++;
    }
    cout << ans << endl;
}