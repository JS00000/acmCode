#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

#define For(i,a,b) for (int i=(a),_##i=(b); i<=_##i; i++)
#define Rof(i,a,b) for (int i=(a),_##i=(b); i>=_##i; i--)

const int maxn=100000+100;
int N,M,K,A[maxn];
long long B[maxn];
map <int,int> Map;

void del(int v)
{
    Map[v]--;
    if (Map[v]==0) Map.erase(v);
}

int main()
{
    int zz=0;
    scanf("%d",&zz);
    For(test,1,zz)
    {
        scanf("%d%d%d",&N,&M,&K);
        For(i,1,N) scanf("%d",&A[i]);
        sort(A+1,A+N+1);
        Map.clear();
        long long ans=0;
        int cnt=0;
        For(i,1,N)
            if (Map.find(A[i])==Map.end())
                Map[A[i]]=1;
            else
                Map[A[i]]++;
        Rof(i,N,1)
        {
            int a=A[i];
            if (Map.find(A[i])==Map.end()) continue;
            int b=-1;
            del(A[i]);
            if (Map.size()==0) continue;
            map <int,int> :: iterator it;
            it=Map.upper_bound(K-A[i]);
            if (it==Map.begin()) continue;
            it--;
            if (it!=Map.end()) b=it->first;
            if (b!=-1)
            {
                B[++cnt]=a*b;
                del(b);
            }
        }
        sort(B+1,B+cnt+1);
        Rof(i,cnt,max(cnt-M+1,1))
            ans+=B[i];
        printf("CASE #%d: %lld\n",test,ans);
    }
    return 0;
}
