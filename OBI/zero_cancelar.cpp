#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
    cin >> n;
    vector<int> vect(n);
    
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        
        x!=0 ? vect.push_back(x) : vect.pop_back();
    }
    
    cout << accumulate(vect.begin(), vect.end(), 0) << endl;

    return 0;
}