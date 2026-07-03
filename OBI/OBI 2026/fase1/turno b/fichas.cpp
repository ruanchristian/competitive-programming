#include <bits/stdc++.h>
using namespace std;

int main() {
	int x;
	cin>>x;
	
	int rs[4]={10,5,2,1};
	
	int cnt=0, k=0;
	while(x>0) {
	    if(rs[k]>x) {
	        k++;
	        continue;
	    }
	    x-=rs[k];
	    cnt++;
	}
	
	cout<<cnt<<endl;
	
	return 0;
}