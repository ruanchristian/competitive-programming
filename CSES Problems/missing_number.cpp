#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool binary(vector<ll>& arr, ll x) {
    ll left = 0, right = arr.size()-1, mid;

    while (left <= right) {
        mid = (left+right)/2;

        if (arr[mid]==x) return true;
        else if (arr[mid] < x) left=mid+1;
        else right=mid-1;
    }
    return false;
} 

int main() {
    ll n;
    cin >> n;

    vector<ll> arr(n-1), aux(n);

    for (ll i = 0; i < n-1; i++) cin >> arr[i];
    for (ll i = 0; i < n; i++) aux[i] = i+1;
    sort(arr.begin(), arr.end());

    ll ans=0;
    for (ll x : aux) {
        if (!binary(arr, x)) {
            ans=x;
            break;
        }
    }

    cout << ans << endl;

    return 0;
}