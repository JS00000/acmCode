#include <cstdio>
using namespace std;

struct node
{
	int x1,y1,x2,y2;
}a,b;

int f()
{

	if ( a.x1 == b.x1 && a.x2 == b.x2 && a.y1 == b.y1 && a.y2 == b.y2 ) return 2;  //完全重叠

	if ( a.x1 < b.x1 && b.x2 < a.x2 && b.y1 < a.y1 && a.y2 < b.y2 ) return 6;
	if ( b.x1 < a.x1 && a.x2 < b.x2 && a.y1 < b.y1 && b.y2 < a.y2 ) return 6;

	if ( a.x1 < b.x1 && b.x2 < a.x2 && b.y1 < a.y1 && a.y2 == b.y2 ) return 5;
	if ( b.x1 < a.x1 && a.x2 < b.x2 && a.y1 < b.y1 && b.y2 == a.y2 ) return 5;
	if ( a.x1 < b.x1 && b.x2 < a.x2 && b.y1 == a.y1 && a.y2 < b.y2 ) return 5;
	if ( b.x1 < a.x1 && a.x2 < b.x2 && a.y1 == b.y1 && b.y2 < a.y2 ) return 5;
	if ( a.x1 < b.x1 && b.x2 == a.x2 && b.y1 < a.y1 && a.y2 < b.y2 ) return 5;
	if ( b.x1 < a.x1 && a.x2 == b.x2 && a.y1 < b.y1 && b.y2 < a.y2 ) return 5;
	if ( a.x1 == b.x1 && b.x2 < a.x2 && b.y1 < a.y1 && a.y2 < b.y2 ) return 5;
	if ( b.x1 == a.x1 && a.x2 < b.x2 && a.y1 < b.y1 && b.y2 < a.y2 ) return 5;

	if ( a.x1 <= b.x1 && b.x2 <= a.x2 && a.y1 <= b.y1 && b.y2 <= a.y2 ) return 3;
	if ( b.x1 <= a.x1 && a.x2 <= b.x2 && b.y1 <= a.y1 && a.y2 <= b.y2 ) return 3;
	if ( a.x2 <= b.x1 || a.y2 <= b.y1 ) return 3;
	if ( b.x2 <= a.x1 || b.y2 <= a.y1 ) return 3;

	return 4;
}


int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d%d",&a.x1, &a.y1, &a.x2, &a.y2);
		scanf("%d%d%d%d",&b.x1, &b.y1, &b.x2, &b.y2);
		printf("%d\n",f() );
	}
	return 0;
}