#include<cstdio>  
#include <cstring>  
#include<cmath>  
#include<iostream>  
#include<algorithm>  
#include<vector>  
using namespace std;  
  
int main ()  
{  
    int n;  
    scanf("%d",&n);  
    if(n%2!=0)  
    {  
        printf("0\n");  
    }  
    else  
    {  
        n/=2;  
        printf("%d\n",(n-1)/2);  
    }  
    return 0;  
}  