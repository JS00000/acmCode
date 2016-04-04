// 线段树
#include <iostream>
#include <cstring>
using namespace std;
#define TREE_SIZE (1<<(17))
class IntervalTree
{
private:

	int _Query(int a, int b, int l, int r, int Ind)
	{
		if (a<=l&&b>=r) return Top[Ind];
		int mid = (l+r)>>1,ret=Cover[Ind];
		cout << Ind << " :" << Cover[Ind] << " " << Top[Ind] << endl;
		if (a<=mid) ret = max(ret,_Query(a,b,l,mid,Ind<<1));
		if (b>mid) ret = max(ret,_Query(a,b,mid+1,r,(Ind<<1)+1));
		return ret;
	}
	void _Modify(int a, int l, int r, int Ind, int d)
	{
		if (l==r&&l==a)
		{
			Cover[Ind] = Top[Ind] = d;
			return;
		}
		int mid = (l+r)>>1;
		if (a<=mid) _Modify(a,l,mid,Ind<<1,d);
		else _Modify(a,mid+1,r,(Ind<<1)+1,d);
		Top[Ind] = max(Top[Ind<<1],Top[(Ind<<1)+1]);
	}
public:
	int Cover[TREE_SIZE],Top[TREE_SIZE];
	int size;
	IntervalTree()
	{
		memset(Cover,0,sizeof(Cover));
		memset(Top,0,sizeof(Top));
		size = (TREE_SIZE>>2)-1;
	}
	IntervalTree(int size):size(size)
	{
		memset(Cover,0,sizeof(Cover));
		memset(Top,0,sizeof(Top));
	}
	int Query(int a, int b)
	{
		return _Query(a,b,1,size,1);
	}
	void Modify(int a,int d)
	{
		return _Modify(a,1,size,1,d);
	}
};

int main(int argc, char const *argv[])
{
	int a[12] = {0,1,2,3,4,5,6,7,8,1,3,7};
	IntervalTree it(100);
	for (int i = 1; i <= 10; ++i)
	{
		it.Modify(i,a[i]);
	}
	cout << it.Query(10,11) << endl;
	for (int i = 0; i < 10; ++i)
	{
		// cout << i << " " << it.Cover[i] << " " << it.Top[i] << endl;
	}
	cin.get();
	return 0;
}