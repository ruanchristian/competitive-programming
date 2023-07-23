#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    string nomeMaior;
    int maior = -1;
    
    while (N--) {
        string c;
        int v;
        cin >> c >> v;
        
        if (v > maior) {
            nomeMaior = c;
            maior = v;
        }
    }
    
    cout << nomeMaior << '\n' << maior;
    
    return 0;
}