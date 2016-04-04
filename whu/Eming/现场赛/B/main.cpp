#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int a,b,ans;
    while  (~scanf("%d %d",&a,&b))
    {

        if ((a-b)%3==0)
        {
            ans = a+b-3;
        }
        else
        {
            ans = a+b-2;
        }
        if ((a==1)&&(b==1)) ans = 0;
        cout << ans << endl;
    }
    return 0;
}
