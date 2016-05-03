#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

bool a[100011] = {0} ;

int main()
{
    int n,x=0,t,b;
    int max = 0,min = 100001;
    cin >> n;
    while(~scanf("%d",&x))
    {
        if (a[x]) t = x;
        a[x] = 1;
        if (x>max) max = x;
        if (x<min) min = x;
    }
    for(int i=min; i<=max;i++)
    {
        if (!a[i]) b = i;
    }
    cout << b << " " << t << endl;
    return 0;
}
