#include <iostream>
#include <iomanip>
using namespace std;
int main(int argc, char const *argv[])
{
	cout << "n e\n- -----------\n0 1\n1 2\n2 2.5\n";
	int it = 2;
	double e = 2.5;
	for (int i = 3; i < 10; ++i)
	{
		it *= i;
		e += 1.0/it;
		cout << fixed << setprecision(9) << i << " " << e << endl;
	}
	return 0;
}