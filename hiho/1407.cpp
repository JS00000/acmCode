// 后缀数组 height[]
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN=100007;
int t1[MAXN],t2[MAXN],c[MAXN];
bool cmp(int *r,int a,int b,int l)
{
    return r[a] == r[b] && r[a+l] == r[b+l];
}
void da(int str[],int sa[],int ra[],int height[],int n,int m)
{
    n++;
    int i, j, p, *x = t1, *y = t2;
    for(i = 0;i < m;i++)c[i] = 0;
    for(i = 0;i < n;i++)c[x[i] = str[i]]++;
    for(i = 1;i < m;i++)c[i] += c[i-1];
    for(i = n-1;i >= 0;i--)sa[--c[x[i]]] = i;
    for(j = 1;j <= n; j <<= 1)
    {
        p = 0;
        for(i = n-j; i < n; i++)y[p++] = i;
        for(i = 0; i < n; i++)if(sa[i] >= j)y[p++] = sa[i] - j;
        for(i = 0; i < m; i++)c[i] = 0;
        for(i = 0; i < n; i++)c[x[y[i]]]++;
        for(i = 1; i < m;i++)c[i] += c[i-1];
        for(i = n-1; i >= 0;i--)sa[--c[x[y[i]]]] = y[i];
        swap(x,y);
        p = 1; x[sa[0]] = 0;
        for(i = 1;i < n;i++)
            x[sa[i]] = cmp(y,sa[i-1],sa[i],j)?p-1:p++;
        if(p >= n)break;
        m = p;
    }
    int k = 0;
    n--;
    for(i = 0;i <= n;i++)ra[sa[i]] = i;
    for(i = 0;i < n;i++)
    {
        if(k)k--;
        j = sa[ra[i]-1];
        while(str[i+k] == str[j+k])k++;
        height[ra[i]] = k;
    }
}
int ra[MAXN],height[MAXN];
int sa[MAXN],num[MAXN];

bool check(int K, int n)
{
    int minsa, maxsa;
    for(int i=1;i<=n;i++)
        if(height[i]< K)
        {
            minsa=sa[i];
            maxsa=sa[i];
        }
        else 
        {
            minsa=min(minsa,sa[i]);
            maxsa=max(maxsa,sa[i]);
            if(maxsa-minsa>=K)return true;
        }
    return false;
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i)scanf("%d",&num[i]);
    num[n] = 0;
    da(num,sa,ra,height,n,1001);
    int l = 0,r = n;
    while(l<=r){
        int mid = (l+r)>>1;
        if(check(mid, n)) l = mid+1;
        else r = mid - 1;
    }
    printf("%d\n",l-1);
    return 0;
}
