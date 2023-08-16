#include <bits/stdc++.h>

using namespace std;

int main() {
    int V, A, F, P;
    
    cin >> V >> A >> F >> P;
    
    int vec[3] = {A,F,P};
    sort(vec, vec+3);
    
    if (A+F+P <= V) cout << 3 << endl;
    else if (vec[0]+vec[1] <= V) cout << 2 << endl;
    else if (V < A && V < F && V < P) cout << 0 << endl;
    else cout << 1 << endl;

    return 0;
}