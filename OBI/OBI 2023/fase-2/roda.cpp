#include <bits/stdc++.h>

using namespace std;

int N, I, P;

int main() {
    cin >> N >> I >> P;
    
    if (I+P <= N) cout << I+P << endl;
    else cout << (I+P)%N << endl;
    
    return 0;
}