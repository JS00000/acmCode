#include <iostream>
#include <algorithm>

using namespace std;



int main(int argc, char const *argv[])
{
	int a[10] = {1,2,3,4,5,6,7,8,9,10};
	do
	{
		for (int i = 0; i < 3; ++i)
		{
			cout << a[i] << " ";
		}
		cout << endl;
	}while(next_permutation(a,a+3));
	cin.get();
	return 0;
}
