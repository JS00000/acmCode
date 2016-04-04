#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int n, a[1001],sum;
    while(cin >> n)
    {
     sum = 0;
     for (int i = 0; i < n ;i++)
     {
         cin >> a[i];
     }
     sort(a,a+n);
     int lastNum = 0,thisNum = 0, last = 0;
     last = a[0]; 
     for (int i = 1; i < n ;i++)
     {
         if   (a[i]>a[i-1]) 
         {
              sum++;
              last = a[i-1];
              lastNum += thisNum;
              thisNum = 0;
         }
         else if(lastNum>0)
         {
              sum++;
              lastNum--;
              thisNum++;
         }
         else
         {
             thisNum++;
         }
     }
     cout << sum << endl;
    }
    return 0;
}
