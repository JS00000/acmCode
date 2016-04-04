#include<cstdio>
using namespace std;
int a,b,c,ji,ou,x,y,z;
int lc(int o,int p)
{
	if (o>=p)  return 0;
	else return p-o;
}
void calc(int o,int p)
{
	if (o>p) {ou+=(o-p) / 2;}//ji+=(o-p) % 2;} 
}
int main()
{
	scanf("%d%d%d",&a,&b,&c);
	scanf("%d%d%d",&x,&y,&z);
	calc(a,x);
	calc(b,y);
	calc(c,z);
	int lack=lc(a,x)+lc(b,y)+lc(c,z);
	if (ou >= lack) printf("Yes");
	else printf("No");
	return 0;
}