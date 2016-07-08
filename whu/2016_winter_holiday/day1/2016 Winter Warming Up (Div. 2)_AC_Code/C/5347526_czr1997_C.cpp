#include<bitset>  
#include<map>  
#include<vector>  
#include<cstdio>  
#include<iostream>  
#include<cstring>  
#include<string>  
#include<algorithm>  
#include<cmath>  
#include<stack>  
#include<queue>  
#include<set>  
#define inf 0x3f3f3f3f  
#define mem(a,x) memset(a,x,sizeof(a))  
  
using namespace std;  
  
typedef long long ll;  
typedef pair<int,int> pii;  
  
inline int in()  
{  
    int res=0;char c;  
    while((c=getchar())<'0' || c>'9');  
    while(c>='0' && c<='9')res=res*10+c-'0',c=getchar();  
    return res;  
}  
const int N=100100;  
  
int a[N],sum[N],ans;  
int main()  
{  
    int n=in();  
    for(int i=0;i<n;i++)  
    {  
        int x=in();  
        sum[x]=sum[x-1]+1;   //这个数的差值为1的最长递增子序列等于前面一个数的最长递增子序列加1  
        ans=max(ans,sum[x]);  
    }  
    cout<<n-ans<<endl;  
    return 0;  
}  