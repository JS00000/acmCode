#include <iostream>
#include <queue>

struct node
{
	int a, b;
	node(){}
	node(int aa, int bb)
	{
		a = aa;
		b = bb;
	}
	bool operator <(const node &r) const
	{
		return a > r.a;
	}
};

using namespace std;
int main(int argc, char const *argv[])
{
	// int a[10] = {1,2,3,4,5,6,7,8,9,10} , n;
	// for (int i = 0; i < 10; ++i)
	// {
	// 	cout << a[i^1] << " ";
	// }
	// cout << endl;
	// int b, c;
	// for (int i = 0; i <= 20; ++i)
	// {
	// 	b = ((i+1)^1) - 1;
	// 	cout << b << " ";
	// }
	// cout << endl;
	// for (int i = 0; i <= 20; ++i)
	// {
	// 	c = i;
	// 	cout << c << " ";
	// }
	// cout << endl;


	priority_queue<int> qi;
	qi.push(1);
	qi.push(20);
	qi.push(2);
	qi.push(10);
	printf("%d\n", qi.top());
	
	priority_queue<int, vector<int>, greater<int> > qb;
	qb.push(20);
	qb.push(2);
	qb.push(5);
	printf("%d\n", qb.top());
	
	priority_queue<node> qn;
	node temp(5,0);
	qn.push(temp);
	temp.a = 6;
	qn.push(temp);
	temp.a = 10;
	qn.push(temp);
	temp.a = 2;
	qn.push(temp);
	printf("%d\n", qn.top().a);
	return 0;
}