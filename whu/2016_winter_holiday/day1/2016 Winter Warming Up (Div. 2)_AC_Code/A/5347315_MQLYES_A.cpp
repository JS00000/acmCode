
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x,y,z;
    int a,b,c;
   scanf("%d%d%d%d%d%d",&x,&y,&z,&a,&b,&c);
   int sum =0 ;
     if( (x-=a)>0)

     {
          sum+=x/2;
     }
     else
     {
          sum+=x;
     }

     if((y-=b )>0)
     {
          sum+=y/2;
     }
     else
     {
         sum+=y;
     }
     if((z-=c)>0)
     {
         sum+=z/2;
     }
     else
     {
         sum+=z;
     }
   //  printf("%d\n",sum);
     if(sum>=0)
        printf("Yes\n");
     else
        printf("No\n");
}
