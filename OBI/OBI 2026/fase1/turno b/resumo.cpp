#include <bits/stdc++.h>
using namespace std;

int main() {
	string n;
	cin>>n;
	
	set<string> st;
	st.insert(n);
	
	int res=0;
	while(1) {
	    int t=n.size();
	    int i=0, p=0;
	    
	    for(int k=0;k<t;k++) {
	        if((n[k]-'0')%2==1) i++;
	        else p++;
	    }

	    string posres=to_string(t)+to_string(i)+to_string(p);
	    if(st.count(posres)) break;
	    
	    st.insert(posres);
	    n=posres;
	    
	    res++;
	}
	
	cout<<res<<endl;
	
	return 0;
}