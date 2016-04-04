#include<cstdio>
using namespace std;
int a[1000][1000];
int main()
{
	a[0][0]=1;
	int p=1,n;
	scanf("%d",&n);
	for (int i=1;i<=9;i++)
	{
		for (int j=0;j<p;j++)
			for (int k=p;k<(p*2);k++)
				a[j][k]=-a[j][2*p-k-1];
		for (int j=p;j<p*2;j++)
		{
			for (int k=0;k<p;k++)
				a[j][k]=a[j-p][k];
			for (int k=p;k<2*p;k++)
				a[j][k]=a[j][2*p-k-1];
		}
		p*=2;
	}
	int l=(1<<n);
	for (int i=0;i<l;i++)
	{
		for (int j=0;j<l;j++)
			printf("%c",((a[i][j] == -1) ? '*' : '+'));
			printf("\n");
	}
	return 0;
}