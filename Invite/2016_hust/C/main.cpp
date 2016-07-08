#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N = 1e6+7;
char s[N];
vector<int> r[N];
struct node
{
    int son[26],l,fa;
    int rightSize;
} a[N];
int tot=1,last=1;
void init()
{
    tot=last=1;
    for (int i=0;i<26;++i)
        a[1].son[i]=0;
    a[1].fa=a[1].l=a[1].rightSize=0;
}
void add(int p,int x)
{
    int q;
    a[last=++tot].l=a[p].l+1;
    a[tot].rightSize=1;
    for (int i=0;i<26;++i)
        a[tot].son[i]=0;
    for (q=p;q&&a[q].son[x]==0;q=a[q].fa) a[q].son[x]=tot;
    if (q)
    {
        int v=a[q].son[x];
        if (a[q].l+1==a[v].l)
            a[tot].fa=v;
        else
        {
            int t=tot++;
            a[tot].l=a[q].l+1;
            a[tot].rightSize=0;
            for (int i=0;i<26;i++)
                a[tot].son[i]=a[v].son[i];
            for (int i=q;i;i=a[i].fa)
                if (a[i].son[x]==v)
                    a[i].son[x]=tot;
            a[tot].fa=a[v].fa;
            a[v].fa=tot;
            a[t].fa=tot;
        }
    }
    else
        a[tot].fa=1;
}
void build(char *s)
{
    for (int i=0;s[i];i++)
        add(last,s[i]-'a');
}

int du[N];
int ord[N],bg,ed;
LL sum1[N][27],sum2[N][27];
void pre()
{
    for (int i=1;i<=tot;++i) du[i]=0;
    for (int i=1;i<=tot;++i)
        ++du[a[i].fa];
    bg=0;ed=-1;
    for (int i=1;i<=tot;++i)
        if (du[i]==0)
            ord[++ed]=i;
    int x,y;
    while (bg<=ed)
    {
        x=ord[bg++];
        y=a[x].fa;
        a[y].rightSize+=a[x].rightSize;
        if (--du[y]==0) ord[++ed]=y;
    }
}
void GetSum()
{
    int x,y;
    for (int i=1;i<=tot;++i) du[i]=0;
    for (int i=1;i<=tot;++i)
        for (int j=0;j<26;++j)
            ++du[a[i].son[j]];
    ord[bg=ed=1]=1;
    while (bg<=ed)
    {
        x=ord[bg++];
        for (int i=0;i<26;++i)
        {
            y=a[x].son[i];
            if (y)
            {
                if (--du[y]==0) ord[++ed]=y;
            }
        }
    }
    for (int j=tot;j>=1;--j)
    {
        x=ord[j];
        sum1[x][0]=1;
        sum2[x][0]=a[x].rightSize;
        for (int i=0;i<26;++i)
        {
            y=a[x].son[i];
            if (y)
            {
                sum1[x][i+1]=sum1[x][i]+sum1[y][26];
                sum2[x][i+1]=sum2[x][i]+sum2[y][26];
            }
            else
            {
                sum1[x][i+1]=sum1[x][i];
                sum2[x][i+1]=sum2[x][i];
            }
        }
    }
}
int main()
{
    int cas;
    scanf("%d",&cas);
    while (cas--)
    {
        scanf("%s",s);
        init();
        build(s);
        pre();
        GetSum();
        scanf("%s",s);
        LL v1=0,v2=0;
        for (int i=0,p=1;s[i];++i)
        {
            int t=s[i]-'a';
            v1+=sum1[p][t];
            v2+=sum2[p][t];
            p=a[p].son[t];
            if (p==0) break;
        }
        cout<<v2-a[1].rightSize<<' '<<v1-1<<endl;
    }
    return 0;
}
