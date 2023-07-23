#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    int v[n];
    for (int i = 0; i < n; i++) cin >> v[i];

    // Kadane
    int ans = 0, s = 0;
    for (int x : v) {
        s += x;
        ans = max(ans, s);
        s = max(s, 0);
    }

    cout << ans << endl;

    return 0;
}