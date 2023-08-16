#include <bits/stdc++.h>

using namespace std;

#define MAXN 100001

int ar[MAXN];
unordered_map<int, int> freq;

int main() {
    int N;
    cin >> N;
    
    for (int i = 0; i < N; i++) cin >> ar[i];
    
    int l = 0, r = 0, ans;
    freq[ar[0]]++;
    
    while (r < N-1) {
        r++;
        freq[ar[r]]++;
        
        while (freq[ar[r]] > 1) {
            freq[ar[l]]--;
            l++;
        }
        
        ans = max(ans, r-l+1);
    }
    
    cout << ans << endl;
    
    return 0;
}