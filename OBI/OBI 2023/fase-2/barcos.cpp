#include <bits/stdc++.h>
using namespace std;

// OBI 2023 Segunda Fase
// Essa resolução não funciona pra todos os casos de teste (57/100)

const int MAXN = 100005;

vector<pair<int, int>> g[MAXN];

bool iCan(int start, int end, int passengersLimit) {
    queue<int> q;
    vector<bool> visited(MAXN, 0);

    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        if (current == end) return true;

        for (const auto& neighbor : g[current]) {
            int next = neighbor.first;
            int passengers = neighbor.second;

            if (!visited[next] && passengers >= passengersLimit) {
                q.push(next);
                visited[next] = true;
            }
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    int N, B;
    cin >> N >> B;

    for (int i = 0; i < B; ++i) {
        int I, J, P; cin >> I >> J >> P;
        g[I].emplace_back(J, P);
        g[J].emplace_back(I, P);
    }

    int C;
    cin >> C;

    while (C--) {
        int X, Y;
        cin >> X >> Y;

        int low = 1, high = INT_MAX, ans = -1;
        while (low <= high) {
            int mid = low + (high-low) / 2;
            if (iCan(X, Y, mid)) {
                ans = mid;
                low = mid+1;
            } else {
                high = mid-1;
            }
        }

        cout << ans << endl;
    }

    return 0;
}