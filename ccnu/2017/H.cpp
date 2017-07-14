#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <map>
using namespace std;
const int MAX_N = 1e6+10;

char s[MAX_N];
int cnt[MAX_N];

int main()
{
    int t;
    while(scanf("%d",&t)!=EOF)
    {

        for(int tt=0; tt<t; tt++)
        {
            scanf("%s",s);
            int len = strlen(s);
            int cc = 0;
            cnt[0] = 0;
            for(int i=1; i<=len; i++)
            {
                if(s[i-1] == '0')
                {
                    cc++;
                }
                cnt[i] = cc;
            }

            //cout << cc<<" ~ "<<len<<endl;
            if(cc == len)
            {
                printf("CASE #%d: -1\n",tt+1);
                continue;
            }
            int xxxx = 0;
            for(int i=1; i <= len; i++)   // 琛ㄧず鍖洪棿闀垮害
            {
                if(len %i != 0) continue;
                //cout<<"i="<<i<<endl;
                int flag = 0;
                for(int j = 1; j <= (len/i); j++)
                {
                    xxxx++;
                    int x = (j-1) * i;
                    int y = j * i;
                    int z = cnt[y] - cnt[x];
                    if(z == i)
                    {
                        flag = 1;
                        break;
                    }
                }
                if(flag == 0)
                {
                    printf("CASE #%d: %d\n",tt+1, len/i);
                    break;
                }
            }
        }
    }
    return 0;
}
