#include <iostream>

using namespace std;

int whatDay(int y, int m, int d)
{
	int ans;
	if (m == 1 || m == 2)
		m += 12, y--;
	if ((y < 1752) || (y == 1752 && m < 9) || (y == 1752 && m == 9 && d < 3))
		ans = (d + 2*m + 3*(m + 1)/5 + y + y /4 + 5) % 7;
	else
		ans = (d + 2*m + 3*(m + 1)/5 + y + y /4 - y/100 + y/400) % 7;
	return ans;
}

int main(int argc, char const *argv[])
{
	cout << whatDay(2016+2800, 4, 1) << endl;
	return 0;
}
