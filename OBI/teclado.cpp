#include <bits/stdc++.h>

using namespace std;

// OBI 2021 - Terceira fase

map<vector<char>, int> mp;

bool busca(char c, int x) {
    for (auto it : mp) {
        if (it.second == x) {
            vector<char> v = it.first;
            if (find(v.begin(), v.end(), c) != v.end()) return true;
        }
    }
    return false;
}

int main() {
    string n;
    int m, ans = 0;
    cin >> n >> m;
    
    // mapeando
    mp.emplace(vector<char>{'a', 'b', 'c'}, 2);
    mp.emplace(vector<char>{'d', 'e', 'f'}, 3);
    mp.emplace(vector<char>{'g', 'h', 'i'}, 4);
    mp.emplace(vector<char>{'j', 'k', 'l'}, 5);
    mp.emplace(vector<char>{'m', 'n', 'o'}, 6);
    mp.emplace(vector<char>{'p', 'q', 'r', 's'}, 7);
    mp.emplace(vector<char>{'t', 'u', 'v'}, 8);
    mp.emplace(vector<char>{'w', 'x', 'y', 'z'}, 9);
    
    while (m--) {
        string s;
        cin >> s;
        if (s.size() > n.size() or s.size() < n.size()) continue;
        
        bool ok = 1;
        for (int i = 0; i < n.size(); i++) {
            if (!busca(s[i], n[i]-'0')) {
                ok = 0;
                break;
            }
        }
        
        if (ok) ans++;
    }
    
    cout << ans << endl;
    
    return 0;
}