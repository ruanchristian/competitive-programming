#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    int n;
    cin >> n;
 
    int v[n];
    for (int i = 0; i < n; i++) cin >> v[i];
 
    long long ans = INT_MIN, s = 0;
    for (int x : v) {
        s += x;
        ans = (ans > s ? ans : s);
        s = (s > 0 ? s : 0);
    }
 
    cout << ans << endl;
 
    return 0;
}