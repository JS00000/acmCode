#include<cstdio>
#include<algorithm>
using namespace std;
const int N=200005;
char out[550][550];
int main()
{
	int in;
	out[1][1]='+';out[1][2]='+';
	out[2][1]='+';out[2][2]='*';
	
	for(int i=2;i<=9;++i)
	{
		// 左上复制到左下
		int l,r,u,d,len=1<<(i-1);
		l=1,r=len,u=1,d=r;
		for(int j=d+1;j<=d+len;++j)
			for(int k=l;k<=len;++k)
				out[j][k]=out[j-len][k];
			
		//左上复制到 右上
		
		u=1; d=u+len-1;
		for(int j=u;j<=d;++j)
			for(int k=r+1;k<=r+len;++k)
				out[j][k]=out[j][k-len];
			
		//左下到右下取反
		
		u=1+len; d=u+len-1;
		for(int j=u;j<=d;++j)
			for(int k=r+1;k<=r+len;++k)
				out[j][k]=( (out[j][k-len]=='+') ? '*' : '+' );

	}
	while(scanf("%d",&in)!=EOF)
	{
		int len=1<<in;
		for(int i=1;i<=len;++i)
		{
			for(int j=1;j<=len;++j)
				printf("%c",out[i][j]);
			printf("\n");
		}
	}
	
		
	
}
		