#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int n;
	int a,b,c;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> a >> b >> c;
		if ((a+b+c==180)&&a!=0&&b!=0&&c!=0&&a!=180&&b!=180&&c!=180)
			cout << "YES" << endl;
		else 
			cout << "NO" << endl;
	}
	return 0;
}