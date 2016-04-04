#include "iostream"

using namespace std;
int main(int argc, char const *argv[])
{
	/* code */
	string str;
	int num[3];
	cin >> str;
	num[0] = (str[0]-'0');
	num[1] = (str[1]-'0');
	num[2] = (str[2]-'0');
	if (num[0]*100+num[1]*10+num[2] == num[0]*num[0]*num[0]+num[1]*num[1]*num[1]+num[2]*num[2]*num[2])
	{
		cout << '1' << endl;
	}
	else {
		cout << '0' << endl;
	}
	return 0;
}