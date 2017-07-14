#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <bitset>
#include <vector>
using namespace std;

const int maxn=4e5+100;
int L1,L2,N,M;
int A[maxn],B[maxn],nex[maxn];

void read(int &len,int &n,int *s)
{
    int r,last;
    scanf("%d%d",&len,&r);
    n=-1; last=0;
    for (int i=1; i<=r; i++)
    {
        int pos,num;
        scanf("%d%d",&pos,&num);
        if (num!=0)
        {
            s[n+1]=-(pos-last-1);
            s[n+2]=num;
            n+=2;
            last=pos;
        }
    }
    s[n+1]=-(len-last);
//for (int i=0; i<=n+1; i++)
//    printf("%d ",s[i]);
//printf("\n");
}

void get_next(int len,int *s,int *nex)
{
    nex[1]=0;
    int j=0;
    for (int i=2; i<=len; i++)
    {
        while(j!=0 && s[i]!=s[j+1]) j=nex[j];
        if (s[i]==s[j+1]) j++;
        nex[i]=j;
    }
}

int KMP(int *B,int *A,int *nex,int m,int n)
{
    int j=0,ret=0;
    for (int i=1; i<=n; i++)
    {
        while(j!=0 && A[i]!=B[j+1]) j=nex[j];
        if (A[i]==B[j+1]) j++;
        if (j==m)
        {
            ret+=(-A[i-m]>=-B[0] && -A[i+1]>=-B[m+1]);
            j=nex[j];
        }
    }
    return ret;
}

int main()
{
    int zz=0;
    scanf("%d",&zz);
    for (int test=1; test<=zz; test++)
    {
        read(L1,N,A);
        read(L2,M,B);
        int ans;
        if (M==-1)
        {
            ans=0;
            for (int i=0; i<=N+1; i+=2)
                if (-A[i]>=L2) ans+=-A[i]-L2+1;
        }
        else
        {
            get_next(M,B,nex);
            ans=KMP(B,A,nex,M,N);
        }
        printf("CASE #%d: %d\n",test,ans);
    }
    return 0;
}
