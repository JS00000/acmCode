#include <iostream>
using namespace std;
int main() {
  int length,way=0;
  cin>>length;
  if(length%2!=0) cout<<way<<endl;
  else {
    length/=2;
    way=(length-1)/2;
    cout<<way<<endl;
  }
  return 0;
}
