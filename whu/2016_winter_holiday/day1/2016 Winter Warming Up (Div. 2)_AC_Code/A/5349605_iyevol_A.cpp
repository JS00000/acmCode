#include <cstdio>
int main()
{
	int a,b,c,x,y,z;
	while(scanf("%d%d%d",&a,&b,&c)!=EOF)
	{
		scanf("%d%d%d",&x,&y,&z);
		a-=x,b-=y,c-=z;
		if(a>0) a>>=1;
		if(b>0) b>>=1;
		if(c>0) c>>=1;
		puts(a+b+c>=0?"Yes":"No");
	}
}