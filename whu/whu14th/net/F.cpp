#include <cstdio>

using namespace std;

int main(int argc, char const *argv[])
{	
	int L, A, B, D, Dir;
	while(scanf("%d%d%d%d%d", &L, &A, &B, &D, &Dir) == 5)
	{
		if (D*2 >= L || (A == B && Dir == 1))
		{
			printf("1.000000\n");
		}
		else
		{
			printf("%6lf\n", double(D*2)/L);
		}
	}
	return 0;
}