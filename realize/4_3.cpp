// 树状数组
#include <iostream>
#include <cstring>

using namespace std;

const int maxn=100000;
int tree[maxn+10] = {0} ;
inline int lowbit(int x)
{
	return (x&-x);
}
void add(int x, int value)
{
	for (int i = x; i <=maxn ; i+=lowbit(i))
	{
		tree[i]+=value;
	}
}
int get(int x)
{
	int sum = 0;
	for (int i = x; i; i-=lowbit(i))
	{
		sum+=tree[i];
	}
	return sum;
}

int main(int argc, char const *argv[])
{
	for (int i = 1; i < 20; ++i)
	{
		add(i,i);
	}
	for (int i = 1; i < 20; ++i)
	{
		cout << i << " " << get(i) << endl;
	}
	cin.get();
	return 0;
}