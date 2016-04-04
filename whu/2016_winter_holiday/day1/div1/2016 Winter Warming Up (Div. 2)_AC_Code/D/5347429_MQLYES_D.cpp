
#include<bits/stdc++.h>
using namespace std;
int main()
{
     int n;
     scanf("%d",&n);
     if(n%2)
     {
          printf("0\n");
          return 0 ;
     }
      n = n/2;

       if(n%2)
       {
            printf("%d\n",n/2);
       }
       else
       {
           printf("%d\n",n/2-1);
       }
}
