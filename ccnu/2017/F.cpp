#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<stack>
#include<time.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define rek(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;

const int maxn=50100;
const int maxm=101;

long long dp[maxn][maxm];
long long a[maxn];
long long sum[maxn];
int n,m;
int q[maxn];
bool judge(int t1,int t2,int t3,int j){
    long long a1=-t1;
    long long b1=sum[t1]+dp[t1][j];
    long long a2=-t2;
    long long b2=sum[t2]+dp[t2][j];
    long long a3=-t3;
    long long b3=sum[t3]+dp[t3][j];
    return (a3-a1)*(b2-b1)+(b3-b1)*(a1-a2)<=0;
}
void vio(){
    rep(j,2,m)
     rep(i,2,n) {
         dp[i][j]=dp[1][j-1]+(long long)(i-1)*a[i]-(sum[i]-sum[1]);
         rep(k,2,i-1) dp[i][j]=min(dp[i][j],dp[k][j-1]+(long long)(i-k)*a[i]-(sum[i]-sum[k]));
     }
    cout<<dp[n][m]<<endl;
}
int main()
{
   // freopen("f.in","r",stdin);
//freopen("f.out","w",stdout);
    int test;
    scanf("%d",&test);
    srand(time(0));
    rep(CASE,1,test){
        scanf("%d%d",&n,&m);
        {
            int x=1;
            rep(i,1,n)
            {
                scanf("%d",&x);
                a[i]=x;
            }
        }


        sum[0]=0;
        rep(i,1,n)
         sum[i]=sum[i-1]+a[i];
        rep(i,1,n)
         dp[i][1]=(long long)i*(long long)a[i]-sum[i];
      //  vio();
        rep(j,2,m)
        {
            int l=1,r=1;
            int ans=1;
            q[r]=1;
            rep(i,2,n){
                while (l+1<=r && dp[q[l]][j-1]+(long long)(-q[l])*a[i]+sum[q[l]]
                       >=dp[q[l+1]][j-1]+(long long)(-q[l+1])*a[i]+sum[q[l+1]]){
                        l++;
                       }
                dp[i][j]=dp[q[l]][j-1]+(long long)(i-q[l])*a[i]-(sum[i]-sum[q[l]]);
                while (l<r && judge(q[r-1],q[r],i,j-1)) r--;
                r++;
                q[r]=i;
            }
        }
        cout<<"CASE #"<<CASE<<": "<<dp[n][m]<<endl;
    }
    return 0;
}
