#include <bits/stdc++.h>

using namespace std;

// Questão do nivel sênior da fase 1

int main() {
    string p;
    cin>>p;
    
    // verifica padrão br 
    if(p.size()==8 && isalpha(p[0]) && isalpha(p[1]) && isalpha(p[2]) && p[3]=='-' 
      && isdigit(p[4]) && isdigit(p[5]) && isdigit(p[6]) && isdigit(p[7])) {
        cout<<"1\n";
        return 0;
    }
     
    // verifica se eh mercosul
    if(p.size()==7 && isalpha(p[0]) && isalpha(p[1]) && isalpha(p[2])
      && isdigit(p[3]) && isalpha(p[4]) && isdigit(p[5]) && isdigit(p[6])) {
          cout<<"2\n";
          return 0;
    }
    
    cout<<"0\n";

    return 0;
}