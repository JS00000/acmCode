#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

const int maxn=1e3+10;
const int maxv=1e6+10;

struct data{int v,p;}z[maxn];

int n,tmp,tot;
int ansi[maxv],ansj[maxv];

void pushans(int i,int j)
{
    tot++;
    ansi[tot]=i;
    ansj[tot]=j;
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&z[i].v),z[i].p=i;
    
    for(int i=1;i<=n/2;i++)swap(z[i],z[i+n/2]);
    
    for(int i=1;i<=n-2;i+=(bool(!z[i].v)))
    {
    	if(z[i].v>z[i+1].v)swap(z[i],z[i+1]);
    	if(z[i+1].v>z[i+2].v)swap(z[i+1],z[i+2]);
    	if(z[i].v>z[i+1].v)swap(z[i],z[i+1]);
    	
        tmp=z[i+1].v/z[i].v;
        for(int j=1;j<=tmp;j<<=1)
            if((j&tmp)!=0)z[i+1].v-=z[i].v,z[i].v<<=1,pushans(z[i+1].p,z[i].p);
            else z[i+2].v-=z[i].v,z[i].v<<=1,pushans(z[i+2].p,z[i].p);
        swap(z[i],z[i+1]);
    }

    printf("%d\n",tot);
    for(int i=1;i<=tot;i++)
        printf("%d %d\n",ansi[i],ansj[i]);
    

    return 0;
}
