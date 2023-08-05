#include <bits/stdc++.h>

using namespace std;

string process(string& str) {
    string resp;
    
    int idx = 0;
    for (int i = 0; i < str.size(); ++i) {
       if (str[i] == '-') {
           resp = str.substr(idx, i-idx) + " loosen " + str.substr(i+1, str.size());
       } else if (str[i] == '+') {
           resp = str.substr(idx, i-idx) + " tighten " + str.substr(i+1, str.size());
       }
    }
    return resp;
}

int main() {
    string s, temp;
    cin >> s;
    
    int indice = 0;
    
    for (int i = 0; i < s.size(); ++i) {
        if (isdigit(s[i]) && isalpha(s[i+1]) || isdigit(s[i]) && i+1 == s.size()) {
            temp = s.substr(indice, i-indice+1);
            indice = i+1;
            
            cout << process(temp) << endl;
        }   
    }
    
    return 0;
}