#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
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

#define bll long long
#define dou double
#define For(i,a,b) for (int i=(a),_##i=(b); i<=_##i; i++)
#define Rof(i,a,b) for (int i=(a),_##i=(b); i>=_##i; i--)
#define Mem(a,b) memset(a,b,sizeof(a))
#define Cpy(a,b) memcpy(a,b,sizeof(b))

const int maxn=1e5+100;
int N,M,mask[maxn],p[maxn];
char s[maxn];
vector <int> R[maxn];

long long solve()
{
    mask[0]=0;
    For(i,1,N)
        mask[i]=mask[i-1]^(1<<(s[i]-'a'));
    For(i,0,N) p[i]=mask[i];
    sort(p,p+N+1);
    M=unique(p,p+N+1)-p-1;
    For(i,0,M) R[i].clear();
    
    static int last[30];
    static map < int,int,greater<int> > Map;
    long long ans=0;
    Map.clear();
    Mem(last,0);
    R[p[0]].push_back(0);  // sort unique涔嬪悗p[0]=0锛宲ush_back浣嶇疆0
    For(i,1,N)
    {
        int bit=mask[i];
        int w=s[i]-'a';
        if (last[w]!=0) Map.erase(last[w]);
        last[w]=i;
        Map[i]=w;
        map <int,int> :: iterator it;
        for (it=Map.begin(); it!=Map.end(); it++)
        {
            int num=lower_bound(p,p+M+1,bit)-p;
            if (p[num]==bit)
                ans+=R[num].end()-lower_bound(R[num].begin(),R[num].end(),it->first);
            bit^=(1<<(it->second));
        }
        int num=lower_bound(p,p+M+1,bit)-p;
        if (p[num]==bit)
            ans+=R[num].end()-lower_bound(R[num].begin(),R[num].end(),0);
        R[lower_bound(p,p+M+1,mask[i])-p].push_back(i);
    }
    return ans;
}

int main()
{
    int zz=0;
    scanf("%d",&zz);
    For(test,1,zz)
    {
        scanf("%s",s+1);
        N=strlen(s+1);
        long long ans=solve();
        printf("CASE #%d: %lld\n",test,ans);
    }
    return 0;
}
