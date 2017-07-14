// 后缀数组 height[]
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn=200007;
int t1[maxn],t2[maxn],c[maxn];
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
int ra[maxn],height[maxn];
int sa[maxn],num[maxn];

int main()
{
    char str[maxn];
    int num[maxn];
    scanf("%s",str);
    int len = strlen(str);
    int len1 = len;
    str[len] = '#';
    scanf("%s",str + len + 1);
    len = strlen(str);
    for (int i = 0; i < len; ++i) num[i] = str[i] - '#' + 1;
    da(num,sa,ra,height,len,101);
    int ans = 0;
    for (int i = 1; i <= len; ++i)
        if ((sa[i-1] < len1 && sa[i] > len1) || (sa[i-1] > len1 && sa[i] < len1)) if (height[i] > ans) ans = height[i];
    printf("%d\n", ans);
    return 0;
}
