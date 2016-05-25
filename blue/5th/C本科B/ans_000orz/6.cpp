#include "iostream"
#include "cstdio"
#include "cmath"


using namespace std;
int main(int argc, char const *argv[])
{
	int sum = 0;
	for (int x1 = 1; x1 < 9; ++x1)
	{
		for (int x2 = 1; x2 < 9; ++x2)
		{
			for (int x3 = 1; x3 < 9; ++x3)
			{
				for (int x4 = 1; x4 < 9; ++x4)
				{
					if ((x1!=x2)&&(x3!=x4))
					{
						if (abs(double(x1)/x2*double(x3)/x4-double(x1*10+x3)/(x2*10+x4))<0.0001)
						{
							sum++;
						}
					}
				}
			}
		}
	}
	cout << sum << endl;
	return 0;
}