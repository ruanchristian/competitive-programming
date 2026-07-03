#include <bits/stdc++.h>
using namespace std;

int main() {
	int mask=0;
	
	bool bit;
	for(int i=4;i>=0;i--) {
	    cin>>bit;
	    mask|=(bit<<i);
	}
	
	cout<<mask<<endl;
	
	return 0;
}