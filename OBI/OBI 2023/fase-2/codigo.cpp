#include <bits/stdc++.h>

using namespace std;

// OBI 2023 - Segunda Fase

int main() {
    int N;
    string s;
    cin >> N >> s;
    
    int count = 1;
    for (int i=1; i<=N; i++) {
        if (s[i] == s[i-1]) count++;
        else {
            cout << count << " " << s[i-1] << " ";
            count = 1;
        }
    }

    return 0;
}