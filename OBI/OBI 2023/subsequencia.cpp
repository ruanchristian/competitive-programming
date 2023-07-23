#include <bits/stdc++.h>

using namespace std;

int A, B;

int main() {
    cin >> A >> B;
    int seqA[A], seqB[B];
    
    for (int i=0; i<A; i++) cin >> seqA[i];
    for (int i=0; i<B; i++) cin >> seqB[i];
    
    int p=0, k=0;
    while(p<A) {
        if (seqA[p] == seqB[k]) k++;
        
        if (k==B) {
            cout << 'S';
            return 0;
        } 
        p++;
    }
    cout << 'N';
    
    return 0;
}