#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	for (int i = 0; i < 2; ++i)
	{
		int t = 3;
		for (int j = 0; j < 2; ++j)
		{
			int a = t;
			int t = a+1;
			cout << t << endl;
		}
	}
	return 0;
}