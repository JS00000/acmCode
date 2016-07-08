#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int a,b,c,x,y,z,m1,m2,m3;
	cin >> a>>b>>c>>x>>y>>z;
	m1 = a-x;
	m2 = b-y;
	m3 = c-z;
	if (m1>0)
	{
		m1/=2;
	}
	if (m2>0)
	{
		m2/=2;
	}
	if (m3>0)
	{
		m3/=2;
	}
	if (m1+m2+m3>=0)
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}
	return 0;
}