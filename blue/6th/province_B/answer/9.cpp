#include <iostream>
#include <cstdio>
#include <cstring>
#define MOD 1000000007
using namespace std;

struct mat
{
    long m[6][6];
};
mat I;
mat mul(mat a,mat b)
{
    int i,j,k;
    long s,temp;
    mat res;
    for(i=0;i<6;i++)
    {
        for(j=0;j<6;j++)
        {
            s=0;
            for(k=0;k<6;k++)
            {
                temp = (a.m[i][k]*b.m[k][j])%MOD;
                while (temp<0)
                {
                    temp += MOD;
                }
                s = (s + temp)%MOD;
            }
            temp = s%MOD;
            while (temp<0)
            {
                temp += MOD;
            }
            res.m[i][j]=temp;
        }
    }
    return res;
}
mat modfast(mat a,int k)
{
     mat res=I;
     while(k)
     {
         if(k&1) res=mul(res,a);
         a=mul(a,a);
         k=k>>1;
     }
     return res;
}
int main(int argc, char** argv)
{
    int x,y,t,m,n;
    long sum;
    mat P,res;
    memset(I.m,0,sizeof(I.m));
    memset(P.m,0,sizeof(P.m));
    for (int i = 0; i < 6; ++i) I.m[i][i]=1;
    for (int i = 0; i < 6; ++i)
        for (int j = 0; j < 6; ++j) P.m[i][j]=1;
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        cin >> x >> y;
        if (y<4)
        {
            t = y+2;
        }
        else
        {
            t = y-4; 
        }
        P.m[x-1][t] = 0;
        if (x<4)
        {
            t = x+2;
        }
        else
        {
            t = x-4; 
        }
        P.m[y-1][t] = 0;
    }
    res = modfast(P,n-1);
    sum = 0;
    for (int i = 0; i < 6; ++i)
    {
        for (int j = 0; j < 6; ++j)
        {
            sum = (sum + res.m[i][j])%MOD;
        }
    }
    long ans = sum*16%MOD;
    while(ans<0)
    {
        ans += MOD;
    }
    cout << ans << "\n";
    return 0;
}
