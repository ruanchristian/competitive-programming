#include <iostream>

// OBI 2019 - Terceira fase

using namespace std;

int main() {
  int A, B;
  cin >> A >> B;
  
  int mesa[3] = {0,1,2};
  
  mesa[A%3]=-1;
  
  if(mesa[B%3] == -1) mesa[(B+1)%3] = -1;
  else mesa[B%3]=-1;
  
  for (int i=0; i<3; i++) {
      if(mesa[i] != -1) cout << mesa[i] << endl;
  }
  
  return 0;
}