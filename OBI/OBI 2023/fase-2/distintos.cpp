#include <bits/stdc++.h>

using namespace std;

int N, ans = 0;

int main() {
    cin >> N;

    vector<int> arr(N);
    unordered_set<int> distincts;

    for (int i = 0; i < N; i++) cin >> arr[i];

    int left = 0, right = 0;

    while (right < N) {
        if (!distincts.count(arr[right])) {
            distincts.insert(arr[right]);
            ans = max(ans, right-left+1);
            right++;
        } else {
            distincts.erase(arr[left]);
            left++;
        }
    }

    cout << ans << endl;

    return 0;
}