#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<int> faixas(N), premios(N+1), ogros(M);
    for (int i = 1; i < N; i++) cin >> faixas[i];
    for (int i = 1; i <= N; i++) cin >> premios[i];
    for (int i = 0; i < M; i++) cin >> ogros[i];
    
    for (int f : ogros) {
        int idx = upper_bound(faixas.begin(), faixas.end(), f) - faixas.begin();
        cout << premios[idx] << " ";
    }

    return 0;
}