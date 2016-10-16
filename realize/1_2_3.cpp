// 单变元模线性方程
// 已知a,b,n,求x,使得ax≡b(mod n)
#include <iostream>
#include <vector>
#define LL long long

using namespace std;

LL gcd_extend(LL a, LL b, LL &x, LL &y)
{
	if (b==0)
	{
		x = 1;
		y = 0;
		return a;
	}
	else
	{
		LL r = gcd_extend(b,a%b,y,x);
		y-=x*(a/b);
		return r;
	}
}

vector<LL> line_mod_equation(LL a, LL b, LL n)
{
	LL x,y;
	LL d = gcd_extend(a,n,x,y);
	vector<LL> ans;
	ans.clear();
	if (b%d==0)
	{
		x%=n;
		x+=n;
		x%=n;
		ans.push_back(x*(b/d)%(n/d));
		for (LL i = 1; i < d; ++i)
		{
			ans.push_back((ans[0]+i*n/d)%n);
		}
	}
	return ans;
}


int main(int argc, char const *argv[])
{
	vector<LL> ans;
	ans = line_mod_equation(3007,1,1007);
	for (std::vector<LL>::iterator it = ans.begin(); it!=ans.end() ; ++it)
	{
		cout << *it << " " << endl;
	}
	cin.get();
	return 0;
}
