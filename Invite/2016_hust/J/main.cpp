#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
#define N 40

char s[N];
int cnt[10],_cnt[10];

int main()
{
	int t;
	scanf("%d",&t);
	while (t--)
	{
		for (int i=0;i<10;++i) cnt[i]=0;
		scanf("%s",s);
		for (int i=0;s[i];++i) ++cnt[s[i]-'0'];
		int len = strlen(s);
		long long ans,x,y,z;
		z=1;
		for (int i=1;i<=len/2;++i) z*=10;
		ans=z;
		for (int i=0; i<10; i++)
			for (int j=i; j<10; j++)
				if (cnt[i]>0 && cnt[j]>0 && (i!=j || cnt[i]>=2))
				{
				    x=y=0;
					for (int k=0; k<10; ++k) _cnt[k] =cnt[k];
					--_cnt[i];
					--_cnt[j];
					for (int k=0; k<=4; ++k)
						while (_cnt[k]>0 && _cnt[9-k]>0)
						{
							--_cnt[k];
							--_cnt[9-k];
							x=x*10+k;
							y=y*10+9-k;
						}
					x=x*10+i;
					y=y*10+j;
					if (i+j<=9)
					{
						for (int k=9; k>=0;)
                        {
                            while (k>=0 && _cnt[k] == 0)
                                --k;
                            if (k>=0)
                            {
                                --_cnt[k];
                                x=x*10+k;
                                while (k>=0 && _cnt[k] == 0)
                                    --k;
                                --_cnt[k];
                                y=y*10+k;
                            }
                        }
					}
					else
					{
						for (int k=0; k<10;)
                        {
                            while (k<10 && _cnt[k] == 0)
                                ++k;
                            if (k<10)
                            {
                                --_cnt[k];
                                x=x*10+k;
                                while (k<10 && _cnt[k] == 0)
                                    ++k;
                                --_cnt[k];
                                y=y*10+k;
                            }
                        }
					}
					ans=min(ans,abs(x+y-z));
				}
		printf("%I64d\n",ans);
	}
	return 0;
}
