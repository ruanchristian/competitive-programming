#include <bits/stdc++.h>
using namespace std;

int main() {
	int g1,g2,g3,g4;
	cin>>g1>>g2>>g3>>g4;
	
	int ans=g4;
	
	while(g3>0) {
	    ans++;
	    g3--;
	    
	    if(g1>0) g1--;
	}
	
	while(g2>0) {
	    ans++;
	    
	    g2--;
	    if(g2>0) g2--;
	    else{
	        if(g1>0) g1--;
	        if(g1>0) g1--;
	    }
	}
	
	ans+=ceil(((double)g1/4));
	
	cout<<ans<<endl;
	
	return 0;
}