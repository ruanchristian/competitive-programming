#include <bits/stdc++.h>

using namespace std;

char resp='N';

int main() {
    vector<int> p(6);
    
    for (int i=0; i<6; i++) cin>>p[i];
    sort(p.begin(), p.end());
    
    int top=p[5];
    p[5]=0;
    
    bool found=0;
    for (int i=0; i<5; i++) {
        if (found) break;
        for (int j=i+1; j<5; j++) {
            if (found) break;
            for (int k=j+1; k<5; k++) {
                if (p[i]+p[j]+p[k] == top) {
                    p[i] = p[j] = p[k] = 0;
                    found=1;
                    break;
                }
            }
        }
    }
    
    if (accumulate(p.begin(), p.end(), 0) == top) resp='S';
    
    cout << resp << endl;
    
    return 0;
}