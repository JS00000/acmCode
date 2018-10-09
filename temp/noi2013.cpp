#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    long long n,now_n;
    int low,x,sum=0;
    cin>>n;
    cin>>x;
    now_n=n;
    for(int i=0;i<8;i++)
    {
        low=now_n%10;
        now_n=now_n/10;
        if(low>x)
            sum=sum+(now_n+1)*pow(10,i);
        else if(low==x)
            sum=sum+now_n*pow(10,i)+1+n%(int)pow(10,i);
        else
            sum=sum+now_n*pow(10,i);
    }
    cout<<sum;
    return 0;
}
