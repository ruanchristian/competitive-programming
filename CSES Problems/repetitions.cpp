#include <bits/stdc++.h>

using namespace std;

int main() {
    string dna;
    cin >> dna;

    int n = dna.size();

    char last = dna[0];
    int aux = 1, ans = 1;

    for (int i = 1; i < n; i++) {
        if (last != dna[i] && i+1 < n) {
            last = dna[i];
            aux = 1;
        } else if (last == dna[i]) 
            aux++;

        ans = max(ans, aux);        
    }
    
    cout << ans << endl;

    return 0;
}