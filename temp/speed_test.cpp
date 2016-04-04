#include <iostream>
#include <ctime>

using namespace std;

const long long n = 1e8;

int tests(const int &a)
{
	return a-1;
}

int main(int argc, char const *argv[])
{
	/* code */
	clock_t start, finish;
	start = clock();

	for (int i = 0; i < n; ++i)
	{
		tests(i);
	}

	finish = clock();
	cout << "\nTime:" << double(finish - start) << endl;
	return 0;
}
