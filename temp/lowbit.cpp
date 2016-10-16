#include <cstdio>

using namespace std;

int lowbit(int x)
{
	return x&(-x);
}

int main(int argc, char const *argv[])
{
	printf("%d\n", lowbit(8));
	return 0;
}