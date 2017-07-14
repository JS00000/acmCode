// 二叉树前序中序求后序
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 100
using namespace std;

char PreO[maxn], InO[maxn];

void solve(int Pl, int Pr, int Il, int Ir)
{
	if (Pl > Pr || Il > Ir) return;
	int i;
	for (i = Il; InO[i] != PreO[Pl] && i < Ir; i++);
	solve(Pl+1, Pl+i-Il, Il, i-1);
	solve(Pl+i-Il+1, Pr, i+1, Ir);
	printf("%c", PreO[Pl]);
}

int main()
{
	while(~scanf("%s%s", PreO, InO)) 
	{
		solve(0, strlen(PreO)-1, 0, strlen(InO)-1);
		printf("\n");
	}
	return 0;
}
