#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn=1e5+1000;
int N,A[maxn],M;
int fib[100];

void trans(int i,long long v,int j,long long *tmp)
{
    tmp[0]+=v*fib[i-j-1];
    tmp[1]+=v*fib[i-j];
}

void skip(int &w,int j,long long *tmp)
{
    if (w==j) return ;
    long long ntmp[2]={0,0};
    trans(w,tmp[0],j,ntmp);
    trans(w+1,tmp[1],j,ntmp);
    tmp[0]=ntmp[0],tmp[1]=ntmp[1];
    w=j;
}

bool check(int w)
{
    long long tmp[2]={1,0}; // fib[w],fib[w+1]
    int i=N;
    while(i>0)
    {
        if (w-A[i]>=M) return 0;
        skip(w,A[i],tmp);
        for (; i>0 && A[i]==w; i--,tmp[0]--);
        while(w>1 && (tmp[0]<0 || tmp[1]<0))
        {
            if (tmp[0]<0 && tmp[1]<0) return 0;
            long long t=tmp[0];
            tmp[0]=tmp[1];
            tmp[1]=t+tmp[1];
            w--;
            for (; i>0 && A[i]==w; i--,tmp[0]--);
        }
        if (tmp[0]>=maxn || tmp[1]>=maxn) return 0;
    }
    return ((w==1) ? (tmp[0]+tmp[1]==0) : (tmp[0]==0 && tmp[1]==0));
}

void Prepare_fib()
{
    for (int i=1; i<100; i++)
        fib[i]=maxn;
    fib[0]=0;
    fib[1]=fib[2]=1;
    for (int i=3; i<100; i++)
    {
        fib[i]=fib[i-1]+fib[i-2];
        if (fib[i]>maxn) 
        {
            M=i;
            fib[i]=maxn;
            break;
        }
    }
}

int main()
{
    int zz=0;
    scanf("%d",&zz);
    Prepare_fib();
    for (int test=1; test<=zz; test++)
    {
        scanf("%d",&N);
        for (int i=1; i<=N; i++)
            scanf("%d",&A[i]);
        sort(A+1,A+N+1);
        int ans=0;
        for (int i=0; i<M+2; i++)
            if (check(A[N]+i))
            {
                ans=A[N]+i;
                break;
            }
        printf("CASE #%d: ",test);
        if (ans)
            printf("%d\n",ans);
        else
            printf("NO\n");
    }
    return 0;
}
