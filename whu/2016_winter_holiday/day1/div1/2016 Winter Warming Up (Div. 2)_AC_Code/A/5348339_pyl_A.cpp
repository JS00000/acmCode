#include <iostream>
using namespace std;
int main() {
   int a[6];
   for(int i=0;i<6;i++) {
     cin>>a[i];
   }
   int r=a[0]-a[3]; if(r>0) r=r/2;
   int s=a[1]-a[4]; if(s>0) s=s/2;
   int t=a[2]-a[5]; if(t>0) t=t/2;
   if(r+s+t>=0) cout<<"Yes"<<endl;
   else cout<<"No"<<endl;
   return 0;
}
