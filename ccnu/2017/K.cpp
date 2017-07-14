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

const int maxn=1e5+100;
int N,M,A[maxn],B[maxn];

int main()
{
    int zz=0;
    scanf("%d",&zz);
    for (int test=1; test<=zz; test++)
    {
        printf("CASE #%d:\n",test);
        scanf("%d%d",&N,&M);
        for (int i=1; i<=N; i++) scanf("%d",&A[i]);
        while(M--)
        {
            int od,x,y;
            scanf("%d%d%d",&od,&x,&y);
            if (od==1) A[x]=y;
            else
            {
                if (y-x>60) { printf("Yes\n"); continue; }
                int cnt=0;
                for (int i=x; i<=y; i++) B[++cnt]=A[i];
                sort(B+1,B+cnt+1);
                bool flag=0;
                for (int i=1; i<=cnt-2; i++)
                    if (B[i]+B[i+1]>B[i+2])
                    {
                        flag=1;
                        break;
                    }
                if (flag)
                    printf("Yes\n");
                else
                    printf("No\n");
            }
        }
    }
    return 0;
}