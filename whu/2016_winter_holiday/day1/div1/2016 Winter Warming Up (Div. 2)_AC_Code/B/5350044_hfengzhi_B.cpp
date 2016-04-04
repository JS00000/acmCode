#include <cstdio>
#include <cstring>
#include <cctype>
#include <cmath>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <string>
#include <bitset>
#include <vector>
#include <iostream>
#include <algorithm>
#define LL __int64
#define INF 0x3f3f3f3f
//#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;

int hoge,foo,bar,t,m,n;
int mapp[505][505];
int fla[505][505];
int main()
{
    memset(fla,0,sizeof(fla));
    int x,y,x1,y1;
    scanf("%d%d%d%d",&x,&y,&x1,&y1);
    char s[100006];
    scanf("%s",s);
    int num=0;
    n=strlen(s);
    for(int i=0; i<n; i++)
    {
          if(fla[x1][y1]==0)
                {
                    printf("1 ");
                    fla[x1][y1]=1;
                    num++;
                }
                else
                {
                    printf("0 ");
                }
        if(s[i]=='U')
        {
            if(x1-1>0)
            {
                x1-=1;
            }

        }
        else   if(s[i]=='D')
        {
            if(x1+1<=x)
            {
                x1+=1;

            }
        }
        else  if(s[i]=='R')
        {
            if(y1+1<=y)
            {
                y1+=1;

            }

        }

        else if(s[i]=='L')
        {
            if(y1-1>0)
            {
                y1-=1;

            }
        }

    }
        printf("%d\n",x*y-num);
    return 0;
}
