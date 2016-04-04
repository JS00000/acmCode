#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
const int N=100005;
char str[N];
char unb[N];
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		memset(unb,0,sizeof(unb));
		int ling=0,ans=0;
		for(int i=1;i<=n;++i)
		{
			scanf("%s",str);
			int len=strlen(str),ok=1,num1=0,num0=0;
			for(int j=0;j<len;++j)
			{
				if(str[j]!='0' && str[j]!='1')
					ok=0;
				if(str[j]=='1')
					++num1;
				if(num1!=0 && str[j]=='0')
					++num0;
			}
			if(num1>1) ok=0;
			if(ok) ans+=num0;
			if(ok  && num1==0) ling=1;
			if(!ok)
			{
				memcpy(unb,str,sizeof(char)*len);
			}
				
		}
		if(ling) puts("0");
		else
		{
			int used=0,ll=strlen(unb);
			for(int i=0;i<ll;++i)
			{
				if(unb[i]!='0')
					used=1;
				if(used) printf("%c",unb[i]);
			}
			if(!used) printf("1");
			for(int i=1;i<=ans;++i)
				printf("0");
			printf("\n");
		}
	}
}
		