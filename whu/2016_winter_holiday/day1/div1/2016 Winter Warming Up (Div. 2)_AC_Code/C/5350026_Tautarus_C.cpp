#include<stdio.h>
#include<math.h>
#include<string.h>

bool pos[100010];
int len[100010];

int main(){
	int i,n;
	scanf("%d",&n);
	memset(pos,false,sizeof(pos));
	for(i=1;i<=n;i++)
	{
		int a;
		scanf("%d",&a);
		if(pos[a-1])
		    len[a]=len[a-1]+1;
		else
		    len[a]=1;
		pos[a]=true;
	}
	int ma=-1;
	for(i=1;i<=n;i++)
	{
		if(len[i]>ma)
		    ma=len[i];
	}
	printf("%d",n-ma);
	return 0;
}