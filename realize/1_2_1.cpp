// 欧几里得算法求最大公约数
#include <iostream>

using namespace std;

int gcd(int a, int b)
{
	return b==0?a:gcd(b, a%b);
}

int main(int argc, char const *argv[])
{
	cout << gcd(68,8) << endl;
	cin.get();
	return 0;
}