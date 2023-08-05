#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int N, D;
char c;
ll M, x = 0, y = 0;

int main() {
    cin >> N >> M;
    
    M*=M;
    
    bool afastou=0;    
    while (N--) {
        cin >> c >> D;
        
        if (c == 'N') y += D;
        else if (c == 'S') y -= D;
        else if (c == 'L') x += D;
        else x -= D;
        
        if (x*x + y*y > M) afastou=1;
    }
    
    cout << afastou << endl;

    return 0;
}