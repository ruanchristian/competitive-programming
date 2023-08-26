#include <bits/stdc++.h>

using namespace std;

int main() {
    int E, M, D;
    cin >> E >> M >> D;

    vector<pair<int, int>> sameGroups(M), diffGroups(D);

    for (int i = 0; i < M; i++) cin >> sameGroups[i].first >> sameGroups[i].second;
    for (int i = 0; i < D; i++) cin >> diffGroups[i].first >> diffGroups[i].second;

    vector<int> studentGroup(E+1);
    for (int i = 0; i < E/3; i++) {
        for (int j = 0; j < 3; j++) {
            int student; cin >> student;
            studentGroup[student] = i;
        }
    }

    int violatedCount = 0;

    for (const auto& pair : sameGroups) {
        if (studentGroup[pair.first] != studentGroup[pair.second]) {
            violatedCount++;
        }
    }

    for (const auto& pair : diffGroups) {
        if (studentGroup[pair.first] == studentGroup[pair.second]) {
            violatedCount++;
        }
    }

    cout << violatedCount << endl;

    return 0;
}