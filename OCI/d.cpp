#include <bits/stdc++.h>

using namespace std;

// Contador de notas - OCI 2023

int n;

int main() {
    cin>>n;
    
    if (n>1000) {
        cout<<"Erro: Valor acima de RS 1000,00\n";
        return 0;
    }
    
    int notas100=n/100; n%=100;
    int notas50=n/50; n%=50;
    int notas20=n/20; n%=20;
    int notas10=n/10; n%=10;
    int notas5=n/5;
    n%=5;
    
    if(notas100) cout<<"Notas de RS 100,00 = "<<notas100<<endl;
    if(notas50) cout<<"Notas de RS 50,00 = "<<notas50<<endl;
    if(notas20) cout<<"Notas de RS 20,00 = "<<notas20<<endl;
    if(notas10) cout<<"Notas de RS 10,00 = "<<notas10<<endl;
    if(notas5) cout<<"Notas de RS 5,00 = "<<notas5<<endl;
    if(n) cout<<"Notas de RS 1,00 = "<<n<<endl;

    return 0;
}