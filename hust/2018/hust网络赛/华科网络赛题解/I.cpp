#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int maxn=1000000+50;
int a[maxn],l[maxn],r[maxn];
inline void scan(int &a)
{
	a=0;
	char c;
	while(c=getchar(),!isdigit(c));a=c-'0';
	while(c=getchar(),isdigit(c))a=a*10+c-'0';
}
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        LL res=0;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++) l[i]=r[i]=i;
        for(int i=2;i<=n;i++){
            int cur=i;
            while(cur>1 && a[i]>=a[cur-1]) cur=l[cur-1];
            l[i]=cur;
        }
        for(int i=n-1;i>=1;i--){
            int cur=i;
            while(cur<n && a[i]>a[cur+1]) cur=r[cur+1];
            r[i]=cur;
        }
        for(int i=1;i<=n;i++) res+=(LL)a[i]*(LL)(i-l[i]+1)*(LL)(r[i]-i+1);
        for(int i=1;i<=n;i++) l[i]=r[i]=i;
        for(int i=2;i<=n;i++){
            int cur=i;
            while(cur>1 && a[i]<=a[cur-1]) cur=l[cur-1];
            l[i]=cur;
        }
        for(int i=n-1;i>=1;i--){
            int cur=i;
            while(cur<n && a[i]<a[cur+1]) cur=r[cur+1];
            r[i]=cur;
        }
        for(int i=1;i<=n;i++) res-=(LL)a[i]*(LL)(i-l[i]+1)*(LL)(r[i]-i+1);
        printf("%lld\n",res);
    }
    return 0;
}
