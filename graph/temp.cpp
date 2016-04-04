#include <iostream>


using namespace std;
int main(int argc, char const *argv[])
{
	int a[10] = {1,2,3,4,5,6,7,8,9,10} , n;
	for (int i = 0; i < 10; ++i)
	{
		cout << a[i^1] << " ";
	}
	cout << endl;
	int b = 10;
	cout << b << endl;
	cin >> n;
	return 0;
}