#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#include<string.h>
#include<algorithm>
#include<cmath>
const int N = 100005;
using namespace std;
bool used[510][510];
char str[100010];
int ans;
int X,Y,X0,Y0,xx,yy;
int ope(char c)
{
	int flag=0;
	if(c=='R')if(yy<Y)
		++yy;
	if(c=='L'&&yy>1)
		--yy;
	if(c=='U'&& xx>1)
		--xx;
	if(c=='D' && xx<X)
		++xx;
	
	if(used[xx][yy]==0)
	{
		flag=1;
		ans--;
	}
	used[xx][yy]=1;
	return flag;
}
int main()
{
	
	scanf("%d%d%d%d",&X,&Y,&X0,&Y0);
	scanf("%s",str);
	ans=X*Y;
	ans--;
	xx=X0,yy=Y0;
	used[X0][Y0]=1;
	int len=strlen(str)-1;
	cout<<"1 ";
	for(int i=0;i<len;i++)
	{
		printf("%d ",ope(str[i]));
	}
	printf("%d\n",ans+ope(str[strlen(str)-1]));
	return 0;
}