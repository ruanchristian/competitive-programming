#include <bits/stdc++.h>

using namespace std;

// OBI 2024 Fase 1 - Questão 2 (Relogio)

int main() {
    int h, m, s, t;
    cin>>h>>m>>s>>t;
    
    // converto o horario somente para segundos
    int segs=(h*3600+m*60+s)+t;
    
    // aritmetica modular
    int hs=(segs/3600)%24;
    int min=(segs/60)%60;
    int sec=segs%60;
    
    cout<<hs<<'\n'<<min<<'\n'<<sec;
    
    return 0;
}
