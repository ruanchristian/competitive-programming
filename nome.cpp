#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int N;
string s;

int main() {
    cin >> N;
    
    ll t;
    while (N--) {
        cin >> t;
        cin.ignore();
        getline(cin, s);
        
        int sz = s.size();
        cout << s.substr(t%sz, sz) + s.substr(0, t%sz) << endl;
    }
}