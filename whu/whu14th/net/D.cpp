#include <cstdio>

using namespace std;

int main(int argc, char const *argv[])
{	
	int n,m;
	while(scanf("%d%d",&n, &m)==2)
	{
		if (n==1 && m==1)
		{
			printf("0\n");
		}
		else printf("%d\n", n<m ? n : m);
	}
	return 0;
}