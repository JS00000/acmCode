#include<bits/stdc++.h>
using namespace std;
const int maxn = 100008;
int a[maxn];
int dp[maxn];
int main()
{
    int n;
    cin>>n;
     for(int i = 1;i<=n;i++)
     {
          scanf("%d",&a[i]);
     }
     int pos;
      int ans = 1;
      for(int i =1 ;i<=n;i++)
      {
            dp[a[i]] = 1;
            dp[a[i]]+=dp[a[i]-1];
            ans  = max(ans ,dp[a[i]]);
      }
      printf("%d\n",n-ans);
}