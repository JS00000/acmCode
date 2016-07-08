#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
int nowx,nowy;
int cx, cy;
int ans;
char a[100010];
int used[505][505];
int cot = 0;
int  judge(char x)
{
    int flag = 0;
    if(x=='U')
    {
        if(nowx-1>=1&&nowx-1<=cx)
        {
            nowx--;
        }
    }
    else if(x=='R')
    {
        if(nowy+1>=1&&nowy+1<=cy)
        {
            nowy++;
        }
    }
    else if(x=='L')
    {
        if(nowy-1>=1&&nowy-1<=cy)
        {
            nowy--;
        }
    }
    else if(x=='D')
    {
        if(nowx+1>=1&&nowx+1<=cx)
        {
            nowx++;
        }
    }
    //cout<<nowx<<nowy<<endl;
  //  printf("dd%d",used[9][9]);
    if(used[nowx][nowy]==0)
    {
        used[nowx][nowy] =1;
        ans--;
        flag = 1;
    }
    return flag;

}
int main()
{
    scanf("%d%d%d%d",&cx,&cy,&nowx,&nowy);
    ans = cx*cy;
    scanf("%s",a);
    int len = strlen(a);
    printf("1 ");
    used[nowx][nowy] = 1;
    ans--;
    for(int i = 0; i<len-1; i++)
    {
        cout<<judge(a[i])<<" ";
    }
      if(judge(a[len-1]))
        ans++;
       printf("%d\n",ans);
}
